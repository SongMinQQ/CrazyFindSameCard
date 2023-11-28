#include "MatchingGame.h"
#include <iostream>

MatchingGame::MatchingGame() : difficulty("Normal") {}

void MatchingGame::startGame() {
    selectDifficulty();
    if (difficulty == "Normal") {
        playNormal();
    }
    else if (difficulty == "Crazy") {
        playCrazy();
    }
}

void MatchingGame::selectDifficulty() {
    std::cout << "난이도를 선택하세요. (Normal/Crazy): ";
    std::cin >> difficulty;
}

void MatchingGame::playNormal() {
    std::cout << "노말 모드를 선택하셨습니다. 게임을 시작합니다.\n";
    // 여기에 Normal 모드의 게임 로직을 구현하세요.
}

void MatchingGame::playCrazy() {
    std::cout << "Crazy모드를 선택하셨습니다. 게임을 시작합니다.\n";
    // 여기에 Crazy 모드의 게임 로직을 구현하세요.
}
