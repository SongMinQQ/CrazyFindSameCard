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
    void handleInput(int input); // �� �Լ��� Control Ŭ������ keyControl ����� �޾� ����մϴ�.
    bool isGameOver(); // ������ �������� Ȯ���ϴ� �Լ�
    void endGame();
    void shuffleUnmatchedCards();

    chrono::time_point<chrono::steady_clock> startTime; // ���� ���� �ð�

    void startTimer() {
        startTime = chrono::steady_clock::now();
    }

    void setGameClearTime() {
        game_time = getTimeElapsed(); // ���� Ŭ���� �ð� ����
    }

    int getGameClearTime() const {
        return game_time; // ���� Ŭ���� �ð� ��ȯ
    }
    int getTimeElapsed() const {
        auto now = chrono::steady_clock::now();
        return chrono::duration_cast<chrono::seconds>(now - startTime).count();
    }

private:
    vector<vector<Card>> cards;
    vector<Card> tempUnmatchedCards; // ��Ī���� ���� ī�带 �ӽ÷� ������ ����

    int count; // ���� Ƚ��
    int game_time; // ���� Ŭ���� �ð�

    int selectedRow, selectedCol;
    Card* firstSelectedCard;
    int gameWidth, gameHeight;
    string difficulty;

};

#endif // CARDGAME_H
