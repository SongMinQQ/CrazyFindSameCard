#ifndef CARDGAME_H
#define CARDGAME_H

#include "Card.h"
#include <vector>
#include <string>

using namespace std;

class CardGame {
public:
    CardGame(int width, int height, const string& difficulty);
    void initializeGame();
    void drawGameBoard();
    void showCardTemporarily(int row, int col);
    void handleInput(int input); // 이 함수는 Control 클래스의 keyControl 결과를 받아 사용합니다.
    void checkMatch(Card* firstCard, Card* secondCard);
    bool isGameOver(); // 게임이 끝났는지 확인하는 함수

private:
    vector<vector<Card>> cards;
    int selectedRow, selectedCol;
    Card* firstSelectedCard;
    int gameWidth, gameHeight;
    string difficulty;

    void selectCard();
    void checkMatch();
    void shuffleCards();
    // 다른 필요한 멤버 함수 및 변수
};

#endif // CARDGAME_H
