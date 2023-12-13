#ifndef CARDGAME_H
#define CARDGAME_H

#include "Card.h"
#include <vector>
#include <string>
#include <chrono>

using namespace std;

class CardGame {
    int count; // ���� Ƚ��
    int game_time; // ���� Ŭ���� �ð�
    std::chrono::time_point<std::chrono::steady_clock> startTime; // ���� ���� �ð�

public:
    CardGame(int width, int height, const string& difficulty);
    void initializeGame();
    void drawGameBoard();
    void showCardTemporarily(int row, int col);
    void handleInput(int input); // �� �Լ��� Control Ŭ������ keyControl ����� �޾� ����մϴ�.
    void checkMatch(Card* firstCard, Card* secondCard);
    bool isGameOver(); // ������ �������� Ȯ���ϴ� �Լ�

    void endGame();

    void startTimer() {
        startTime = std::chrono::steady_clock::now();
    }

    void setGameClearTime() {
        game_time = getTimeElapsed(); // ���� Ŭ���� �ð� ����
    }

    int getGameClearTime() const {
        return game_time; // ���� Ŭ���� �ð� ��ȯ
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
    // �ٸ� �ʿ��� ��� �Լ� �� ����
};

#endif // CARDGAME_H
