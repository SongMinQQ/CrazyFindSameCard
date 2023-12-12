#include "CardGame.h"
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

CardGame::CardGame(int width, int height, const string& diff)
    : gameWidth(width), gameHeight(height), difficulty(diff),
    selectedRow(0), selectedCol(0), firstSelectedCard(nullptr) {}

void CardGame::initializeGame() {
    // ī�带 �ʱ�ȭ�ϰ� ���� ����
    cards.clear();
    cards.resize(gameHeight, vector<Card>(gameWidth));
    char cardValue = 'A';

    // ī�� �Ҵ�
    for (int row = 0; row < gameHeight; ++row) {
        for (int col = 0; col < gameWidth; ++col) {
            cards[row][col] = Card(cardValue);
            if ((row * gameWidth + col) % 2 == 1) {
                // ���� ī�� ������ �Ѿ
                cardValue = cardValue == 'Z' ? 'A' : cardValue + 1;
            }
        }
    }

    // ī�� ����
    srand(static_cast<unsigned>(time(0)));
    for (auto& row : cards) {
        random_shuffle(row.begin(), row.end());
    }

    // �ٸ� �ʱ�ȭ �ڵ�...
}

void CardGame::drawGameBoard() {
    // ī�� ���带 �׸��� ����
    for (const auto& row : cards) {
        for (const auto& card : row) {
            char displayChar = card.matched ? card.value : '*';
            cout << displayChar << " ";
        }
        cout << endl;
    }
}

// handleInput �� ��Ÿ �ʿ��� �Լ� ����...
