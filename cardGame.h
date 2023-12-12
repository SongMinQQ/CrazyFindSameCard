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
    void handleInput(int input); // �� �Լ��� Control Ŭ������ keyControl ����� �޾� ����մϴ�.
    bool isGameOver(); // ������ �������� Ȯ���ϴ� �Լ�

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
