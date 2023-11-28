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
    std::cout << "���̵��� �����ϼ���. (Normal/Crazy): ";
    std::cin >> difficulty;
}

void MatchingGame::playNormal() {
    std::cout << "�븻 ��带 �����ϼ̽��ϴ�. ������ �����մϴ�.\n";
    // ���⿡ Normal ����� ���� ������ �����ϼ���.
}

void MatchingGame::playCrazy() {
    std::cout << "Crazy��带 �����ϼ̽��ϴ�. ������ �����մϴ�.\n";
    // ���⿡ Crazy ����� ���� ������ �����ϼ���.
}
