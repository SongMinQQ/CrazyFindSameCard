#ifndef CARDGAME_H
#define CARDGAME_H

#include "Card.h"
#include <vector>
#include <string>
#include <chrono>

using namespace std;

class CardGame {
public:

    CardGame(int width, int height, const string& difficulty);
    void initializeGame();
    void drawGameBoard();
    void showCardTemporarily(int row, int col);
    void handleInput(int input); // 이 함수는 Control 클래스의 keyControl 결과를 받아 사용합니다.
    bool isGameOver(); // 게임이 끝났는지 확인하는 함수
    void endGame();
    void shuffleUnmatchedCards();

    chrono::time_point<chrono::steady_clock> startTime; // 게임 시작 시간

    void startTimer() {
        startTime = chrono::steady_clock::now();
    }

    void setGameClearTime() {
        game_time = getTimeElapsed(); // 게임 클리어 시간 설정
    }

    int getGameClearTime() const {
        return game_time; // 게임 클리어 시간 반환
    }
    int getTimeElapsed() const {
        auto now = chrono::steady_clock::now();
        return chrono::duration_cast<chrono::seconds>(now - startTime).count();
    }

private:
    vector<vector<Card>> cards;
    vector<Card> tempUnmatchedCards; // 매칭되지 않은 카드를 임시로 저장할 벡터

    int count; // 선택 횟수
    int game_time; // 게임 클리어 시간

    int selectedRow, selectedCol;
    Card* firstSelectedCard;
    int gameWidth, gameHeight;
    string difficulty;

};

#endif // CARDGAME_H
