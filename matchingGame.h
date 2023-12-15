#ifndef MATCHINGGAME_H
#define MATCHINGGAME_H
#include "Control.h"
#include "CardGame.h"
#include <vector>
#include <string>
using namespace std;

class MatchingGame : public control {
public:
    MatchingGame() { // cardGame 생성자 초기화ㅇ
        cardGame = nullptr; // 초기에는 nullptr로 설정
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
