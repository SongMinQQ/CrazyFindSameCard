#ifndef CARDGAME_H
#define CARDGAME_H

#include "Card.h"
#include <vector>
#include <string>
#include <chrono>

using namespace std;

class CardGame {
    int count; // 선택 횟수
    int game_time; // 게임 클리어 시간
    std::chrono::time_point<std::chrono::steady_clock> startTime; // 게임 시작 시간

public:
    CardGame(int width, int height, const string& difficulty);
    void initializeGame();
    void drawGameBoard();
    void showCardTemporarily(int row, int col);
    void handleInput(int input); // 이 함수는 Control 클래스의 keyControl 결과를 받아 사용합니다.
    void checkMatch(Card* firstCard, Card* secondCard);
    bool isGameOver(); // 게임이 끝났는지 확인하는 함수

    void endGame();

    void startTimer() {
        startTime = std::chrono::steady_clock::now();
    }

    void setGameClearTime() {
        game_time = getTimeElapsed(); // 게임 클리어 시간 설정
    }

    int getGameClearTime() const {
        return game_time; // 게임 클리어 시간 반환
    }
    int getTimeElapsed() const {
        auto now = std::chrono::steady_clock::now();
        return std::chrono::duration_cast<std::chrono::seconds>(now - startTime).count();
    }

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
