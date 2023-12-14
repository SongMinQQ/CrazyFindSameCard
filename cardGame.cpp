#include "CardGame.h"
#include "Control.h"

#include <iostream>
#include <algorithm>
#include <ctime>
#include <random>  // std::default_random_engine과 std::shuffle을 사용하기 위함


#include <chrono>
#include <thread>

using namespace std;

CardGame::CardGame(int width, int height, const string& diff)
    : gameWidth(width), gameHeight(height), difficulty(diff),
    selectedRow(0), selectedCol(0), firstSelectedCard(nullptr), count(0) {
    // count를 0으로 초기화
}

void CardGame::initializeGame() {
    cards.clear();
    cards.resize(gameHeight, vector<Card>(gameWidth));
    char cardValue = 'A';

    // 카드 할당
    for (int i = 0; i < gameHeight * gameWidth / 2; ++i) {
        cards[i / gameWidth][i % gameWidth] = Card(cardValue);
        cards[(i + gameHeight * gameWidth / 2) / gameWidth][(i + gameHeight * gameWidth / 2) % gameWidth] = Card(cardValue);
        cardValue = cardValue == 'Z' ? 'A' : cardValue + 1;
    }

    // 카드 섞기
    std::random_device rd;
    std::default_random_engine engine(rd());
    for (auto& row : cards) {
        std::shuffle(row.begin(), row.end(), engine);
    }
    
    // 다른 초기화 코드...
}

void CardGame::drawGameBoard() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들 얻기

    cout << "   게임 난이도: " << difficulty
        << "            count: " << count << endl;


    cout << "-----------------------------------------------------------------------------" << endl;
    for (int row = 0; row < gameHeight; ++row) {
        // 각 카드의 상단 테두리 그리기
        for (int col = 0; col < gameWidth; ++col) {
            if (row == selectedRow && col == selectedCol) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); // 초록색으로 변경
            }

            cout << "┌────┐ ";

            if (row == selectedRow && col == selectedCol) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 기본 색상으로 복원
            }
        }
        cout << endl;

        // 각 카드의 중앙 부분 그리기
        for (int col = 0; col < gameWidth; ++col) {
            if (row == selectedRow && col == selectedCol) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); // 초록색으로 변경
            }

            cout << "│";
            if (cards[row][col].matched || cards[row][col].selected) {
                cout << "  " << cards[row][col].value << " ";
            }
            else {
                cout << "  * ";
            }
            cout << "│ ";

            if (row == selectedRow && col == selectedCol) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 기본 색상으로 복원
            }
        }
        cout << endl;

        // 각 카드의 하단 테두리 그리기
        for (int col = 0; col < gameWidth; ++col) {
            if (row == selectedRow && col == selectedCol) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); // 초록색으로 변경
            }

            cout << "└────┘ ";

            if (row == selectedRow && col == selectedCol) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 기본 색상으로 복원
            }
        }
        cout << endl;
    }
}

void CardGame::showCardTemporarily(int row, int col) {
    // 카드를 선택한 위치 확인
    if (row < 0 || row >= gameHeight || col < 0 || col >= gameWidth) return;

    // 선택한 카드가 이미 매칭된 상태이면 무시
    if (cards[row][col].matched) return;

    // 카드 값을 화면에 표시
    cards[row][col].selected = true;
    system("cls");
    drawGameBoard();

    // 1초 대기
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // 게임 보드 다시 그리기 (이 함수 내에서는 카드 상태 변경 없음)
    system("cls");
    drawGameBoard();
}

void CardGame::handleInput(int input) {
    // 입력에 따라 선택된 카드의 위치를 업데이트
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
        // 현재 선택된 카드 가져오기
        Card* selectedCard = &cards[selectedRow][selectedCol];

        if (!firstSelectedCard) {
            // 첫 번째 카드를 선택하는 경우: 이미 매칭된 카드는 처리하지 않음
            if (selectedCard->matched) {
                return;
            }
            firstSelectedCard = selectedCard;
            firstSelectedCard->selected = true;
        }
            else {
                // 두 번째 카드를 선택하는 경우
                if (selectedCard != firstSelectedCard && !selectedCard->matched) {
                    selectedCard->selected = true;
                    count++; // 카운트 즏가
                    system("cls");
                    drawGameBoard(); // 두 번째 카드 선택 시 보드 업데이트
                    if (firstSelectedCard->value == selectedCard->value) {
                        // 매칭 성공
                        firstSelectedCard->matched = true;
                        selectedCard->matched = true;
                    }
                    else {
                        // 매칭 실패: 카드를 일시적으로 보여주고 가리기
                        showCardTemporarily(selectedRow, selectedCol);
                        firstSelectedCard->selected = false;
                        selectedCard->selected = false;

                        // "Crazy" 모드에서만 카드를 다시 섞음
                        if (difficulty == "Crazy") {
                            shuffleUnmatchedCards();
                        }

                    }
                    firstSelectedCard = nullptr; // 선택 초기화
                }
            }
            break;
        }
    }

void CardGame::checkMatch(Card* firstCard, Card* secondCard) {
    if (firstCard && secondCard && firstCard != secondCard) {
        if (firstCard->value == secondCard->value) {
            // 매칭 성공
            firstCard->matched = true;
            secondCard->matched = true;
        }
        else {
            // 매칭 실패
            // 필요한 경우 처리
        }
    }
}

bool CardGame::isGameOver() {
    for (const auto& row : cards) {
        for (const auto& card : row) {
            if (!card.matched) {
                return false; // 아직 매칭되지 않은 카드가 있으면 게임 계속
            }
        }
    }
    return true; // 모든 카드가 매칭되었으면 게임 종료
}

void CardGame::endGame() {
    setGameClearTime(); // 게임 클리어 시간 기록
    system("cls");
    cout << "게임 클리어! 시간: " << getGameClearTime() << " 초" << endl;
    cout << "\n --- 아무 키나 누르세요 --- " << endl;
    _getch(); // 사용자의 키 입력을 기다림
}

void CardGame::shuffleUnmatchedCards() {
    std::random_device rd;
    std::default_random_engine engine(rd());

    tempUnmatchedCards.clear(); // 벡터를 초기화합니다.

    for (int row = 0; row < gameHeight; ++row) {
        for (int col = 0; col < gameWidth; ++col) {
            if (!cards[row][col].matched) {
                // 매칭되지 않은 카드를 임시 벡터에 저장
                tempUnmatchedCards.push_back(cards[row][col]);
            }
        }
    }

    // 임시 벡터의 카드를 섞음
    std::shuffle(tempUnmatchedCards.begin(), tempUnmatchedCards.end(), engine);

    // 섞은 카드를 다시 게임 보드에 배치
    int index = 0;
    for (int row = 0; row < gameHeight; ++row) {
        for (int col = 0; col < gameWidth; ++col) {
            if (!cards[row][col].matched) {
                cards[row][col] = tempUnmatchedCards[index++];
            }
        }
    }
}
