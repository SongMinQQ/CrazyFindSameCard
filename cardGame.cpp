#include "CardGame.h"
#include "Control.h"

#include <iostream>
#include <algorithm>
#include <ctime>
#include <random>  // std::default_random_engine�� std::shuffle�� ����ϱ� ����


#include <chrono>
#include <thread>

using namespace std;

CardGame::CardGame(int width, int height, const string& diff)
    : gameWidth(width), gameHeight(height), difficulty(diff),
    selectedRow(0), selectedCol(0), firstSelectedCard(nullptr), count(0) {
    // count�� 0���� �ʱ�ȭ
}

void CardGame::initializeGame() {
    cards.clear();
    cards.resize(gameHeight, vector<Card>(gameWidth));
    char cardValue = 'A';

    // ī�� �Ҵ�
    for (int i = 0; i < gameHeight * gameWidth / 2; ++i) {
        cards[i / gameWidth][i % gameWidth] = Card(cardValue);
        cards[(i + gameHeight * gameWidth / 2) / gameWidth][(i + gameHeight * gameWidth / 2) % gameWidth] = Card(cardValue);
        cardValue = cardValue == 'Z' ? 'A' : cardValue + 1;
    }

    // ī�� ����
    std::random_device rd;
    std::default_random_engine engine(rd());
    for (auto& row : cards) {
        std::shuffle(row.begin(), row.end(), engine);
    }
    
    // �ٸ� �ʱ�ȭ �ڵ�...
}

void CardGame::drawGameBoard() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // �ܼ� �ڵ� ���

    cout << "   ���� ���̵�: " << difficulty
        << "            count: " << count << endl;


    cout << "-----------------------------------------------------------------------------" << endl;
    for (int row = 0; row < gameHeight; ++row) {
        // �� ī���� ��� �׵θ� �׸���
        for (int col = 0; col < gameWidth; ++col) {
            if (row == selectedRow && col == selectedCol) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); // �ʷϻ����� ����
            }

            cout << "������������ ";

            if (row == selectedRow && col == selectedCol) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // �⺻ �������� ����
            }
        }
        cout << endl;

        // �� ī���� �߾� �κ� �׸���
        for (int col = 0; col < gameWidth; ++col) {
            if (row == selectedRow && col == selectedCol) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); // �ʷϻ����� ����
            }

            cout << "��";
            if (cards[row][col].matched || cards[row][col].selected) {
                cout << "  " << cards[row][col].value << " ";
            }
            else {
                cout << "  * ";
            }
            cout << "�� ";

            if (row == selectedRow && col == selectedCol) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // �⺻ �������� ����
            }
        }
        cout << endl;

        // �� ī���� �ϴ� �׵θ� �׸���
        for (int col = 0; col < gameWidth; ++col) {
            if (row == selectedRow && col == selectedCol) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); // �ʷϻ����� ����
            }

            cout << "������������ ";

            if (row == selectedRow && col == selectedCol) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // �⺻ �������� ����
            }
        }
        cout << endl;
    }
}

void CardGame::showCardTemporarily(int row, int col) {
    // ī�带 ������ ��ġ Ȯ��
    if (row < 0 || row >= gameHeight || col < 0 || col >= gameWidth) return;

    // ������ ī�尡 �̹� ��Ī�� �����̸� ����
    if (cards[row][col].matched) return;

    // ī�� ���� ȭ�鿡 ǥ��
    cards[row][col].selected = true;
    system("cls");
    drawGameBoard();

    // 1�� ���
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // ���� ���� �ٽ� �׸��� (�� �Լ� �������� ī�� ���� ���� ����)
    system("cls");
    drawGameBoard();
}

void CardGame::handleInput(int input) {
    // �Է¿� ���� ���õ� ī���� ��ġ�� ������Ʈ
    switch (input) {
    case UP:
        selectedRow = max(0, selectedRow - 1);
        break;
    case DOWN:
        selectedRow = min(gameHeight - 1, selectedRow + 1);
        break;
    case LEFT:
        selectedCol = max(0, selectedCol - 1);
        break;
    case RIGHT:
        selectedCol = min(gameWidth - 1, selectedCol + 1);
        break;
    case SUBMIT:
        // ���� ���õ� ī�� ��������
        Card* selectedCard = &cards[selectedRow][selectedCol];

        if (!firstSelectedCard) {
            // ù ��° ī�带 �����ϴ� ���: �̹� ��Ī�� ī��� ó������ ����
            if (selectedCard->matched) {
                return;
            }
            firstSelectedCard = selectedCard;
            firstSelectedCard->selected = true;
        }
            else {
                // �� ��° ī�带 �����ϴ� ���
                if (selectedCard != firstSelectedCard && !selectedCard->matched) {
                    selectedCard->selected = true;
                    count++; // ī��Ʈ �Z��
                    system("cls");
                    drawGameBoard(); // �� ��° ī�� ���� �� ���� ������Ʈ
                    if (firstSelectedCard->value == selectedCard->value) {
                        // ��Ī ����
                        firstSelectedCard->matched = true;
                        selectedCard->matched = true;
                    }
                    else {
                        // ��Ī ����: ī�带 �Ͻ������� �����ְ� ������
                        showCardTemporarily(selectedRow, selectedCol);
                        firstSelectedCard->selected = false;
                        selectedCard->selected = false;

                        // "Crazy" ��忡���� ī�带 �ٽ� ����
                        if (difficulty == "Crazy") {
                            shuffleUnmatchedCards();
                        }

                    }
                    firstSelectedCard = nullptr; // ���� �ʱ�ȭ
                }
            }
            break;
        }
    }

void CardGame::checkMatch(Card* firstCard, Card* secondCard) {
    if (firstCard && secondCard && firstCard != secondCard) {
        if (firstCard->value == secondCard->value) {
            // ��Ī ����
            firstCard->matched = true;
            secondCard->matched = true;
        }
        else {
            // ��Ī ����
            // �ʿ��� ��� ó��
        }
    }
}

bool CardGame::isGameOver() {
    for (const auto& row : cards) {
        for (const auto& card : row) {
            if (!card.matched) {
                return false; // ���� ��Ī���� ���� ī�尡 ������ ���� ���
            }
        }
    }
    return true; // ��� ī�尡 ��Ī�Ǿ����� ���� ����
}

void CardGame::endGame() {
    setGameClearTime(); // ���� Ŭ���� �ð� ���
    system("cls");
    cout << "���� Ŭ����! �ð�: " << getGameClearTime() << " ��" << endl;
    cout << "\n --- �ƹ� Ű�� �������� --- " << endl;
    _getch(); // ������� Ű �Է��� ��ٸ�
}

void CardGame::shuffleUnmatchedCards() {
    std::random_device rd;
    std::default_random_engine engine(rd());

    tempUnmatchedCards.clear(); // ���͸� �ʱ�ȭ�մϴ�.

    for (int row = 0; row < gameHeight; ++row) {
        for (int col = 0; col < gameWidth; ++col) {
            if (!cards[row][col].matched) {
                // ��Ī���� ���� ī�带 �ӽ� ���Ϳ� ����
                tempUnmatchedCards.push_back(cards[row][col]);
            }
        }
    }

    // �ӽ� ������ ī�带 ����
    std::shuffle(tempUnmatchedCards.begin(), tempUnmatchedCards.end(), engine);

    // ���� ī�带 �ٽ� ���� ���忡 ��ġ
    int index = 0;
    for (int row = 0; row < gameHeight; ++row) {
        for (int col = 0; col < gameWidth; ++col) {
            if (!cards[row][col].matched) {
                cards[row][col] = tempUnmatchedCards[index++];
            }
        }
    }
}
