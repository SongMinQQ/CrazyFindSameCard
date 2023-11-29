#ifndef MATCHINGGAME_H
#define MATCHINGGAME_H
#include "Control.h"
#include <string>
using namespace std;
class MatchingGame : public control {
public:
    MatchingGame();
    void startGame();
    void selectDifficulty();
    void GameName();
    int menuDraw();
    void GameInfo();
    int GameMode();

private:
    std::string difficulty;
    void playNormal();
    void playCrazy();
};

#endif
