#include "CardGame.h"
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

CardGame::CardGame(int width, int height, const string& diff)
    : gameWidth(width), gameHeight(height), difficulty(diff),
    selectedRow(0), selectedCol(0), firstSelectedCard(nullptr) {}

void CardGame::initializeGame() {
    // 카드를 초기화하고 섞는 로직
    cards.clear();
    cards.resize(gameHeight, vector<Card>(gameWidth));
    char cardValue = 'A';

    // 카드 할당
    for (int row = 0; row < gameHeight; ++row) {
        for (int col = 0; col < gameWidth; ++col) {
            cards[row][col] = Card(cardValue);
            if ((row * gameWidth + col) % 2 == 1) {
                // 다음 카드 값으로 넘어감
                cardValue = cardValue == 'Z' ? 'A' : cardValue + 1;
            }
        }
    }

    // 카드 섞기
    srand(static_cast<unsigned>(time(0)));
    for (auto& row : cards) {
        random_shuffle(row.begin(), row.end());
    }

    // 다른 초기화 코드...
}

void CardGame::drawGameBoard() {
    // 카드 보드를 그리는 로직
    for (const auto& row : cards) {
        for (const auto& card : row) {
            char displayChar = card.matched ? card.value : '*';
            cout << displayChar << " ";
        }
        cout << endl;
    }
}

// handleInput 및 기타 필요한 함수 구현...
