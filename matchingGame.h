#ifndef MATCHINGGAME_H
#define MATCHINGGAME_H
#include "Control.h"
#include "CardGame.h"
#include <vector>
#include <string>
using namespace std;

class MatchingGame : public control {
public:
    MatchingGame() { // cardGame ������ �ʱ�ȭ��
        cardGame = nullptr; // �ʱ⿡�� nullptr�� ����
    }
    void startGame();
    void playGame(const string& mode, int width, int height);
    void GameName();
    int menuDraw();
    void GameInfo();
    int GameMode();
    void init();

private:
    string difficulty;
    CardGame* cardGame;
};

#endif
