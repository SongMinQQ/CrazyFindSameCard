#ifndef MATCHINGGAME_H
#define MATCHINGGAME_H

#include <string>

class MatchingGame {
public:
    MatchingGame();
    void startGame();
    void selectDifficulty();

private:
    std::string difficulty;
    void playNormal();
    void playCrazy();
};

#endif
