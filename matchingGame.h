#ifndef MATCHINGGAME_H
#define MATCHINGGAME_H
#include "Control.h"
#include "CardGame.h"
#include <vector>
#include <string>
using namespace std;

class MatchingGame : public control {
public:
    //CardGame cardGame;
    MatchingGame();
    void startGame();
    void selectDifficulty();
    void GameName();
    int menuDraw();
    void GameInfo();
    int GameMode();
    void waitForInput();

private:
    string difficulty;
    CardGame* cardGame;
    void playNormal();
    void playCrazy();
};

#endif
