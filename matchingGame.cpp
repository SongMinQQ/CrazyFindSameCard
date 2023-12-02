#include "MatchingGame.h"
#include "Control.h"
#include <iostream>

MatchingGame::MatchingGame() : difficulty("Normal") {}

void MatchingGame::startGame() {
	while (true) {
		GameName();
		int menuKey = menuDraw();
		if (menuKey == 0) {//게임시작
			int GameModeKey = GameMode();
			if (GameModeKey == 0) { // 노말

			}
			else if (GameModeKey == 1) { // 크레이지

			}
			// GameModeKey == 2 는 뒤로가기므로 if문 탈출
		}
		else if (menuKey == 1) {//게임 방법
			GameInfo();
		}
		else if (menuKey == 2) {
			return; // 게임 종료
		}
		system("cls");
	}

	system("cls"); // 화면 초기화



	//selectDifficulty();
	//if (difficulty == "Normal") {
	//    playNormal();
	//}
	//else if (difficulty == "Crazy") {
	//    playCrazy();
	//}
}

//void MatchingGame::selectDifficulty() {
//    std::cout << "난이도를 선택하세요. (Normal/Crazy): ";
//    std::cin >> difficulty;
//}
//
//void MatchingGame::playNormal() {
//    std::cout << "노말 모드를 선택하셨습니다. 게임을 시작합니다.\n";
//    // 여기에 Normal 모드의 게임 로직을 구현하세요.
//}
//
//void MatchingGame::playCrazy() {
//    std::cout << "Crazy모드를 선택하셨습니다. 게임을 시작합니다.\n";
//    // 여기에 Crazy 모드의 게임 로직을 구현하세요.
//}

void MatchingGame::GameName() {
	cout << "\n\n\n\n";
	cout << "         ###    #    ####   ####     ####     #     # #   ####\n";
	cout << "        #      # #   #   #  #   #   #        # #   # # #  #   \n";
	cout << "        #     #####  ####   #   #   # ####  #####  # # #  ####\n";
	cout << "        #     #   #  #   #  #   #   #    #  #   #  # # #  #   \n";
	cout << "         ###  #   #  #   #  ####     ####   #   #  # # #  ####\n";
}

int MatchingGame::menuDraw() {
	int x = 24;
	int y = 12;
	gotoxy(x - 2, y);
	cout << "> 게 임 시 작";
	gotoxy(x, y + 1);
	cout << "게 임 정 보";
	gotoxy(x, y + 2);
	cout << "   종 료   ";
	while (true) {
		int key = keyControl();
		switch (key)
		{
		case UP: {
			if (y > 12) {
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, --y);
				cout << ">";
			}
			break;
		}
		case DOWN: {
			if (y < 14) {
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, ++y);
				cout << ">";
			}
			break;
		}
		case SUBMIT: {
			return y - 12;
		}
		}
	}
}

void MatchingGame::GameInfo() {
	system("cls"); // 화면 초기화
	cout << "\n\n";
	cout << "                                    [ 조 작 법 ]\n\n";
	cout << "                         이 동 : W, A, S, D\n";
	cout << "                         선 택 : 스 페 이 스 바\n\n\n\n\n\n\n";
	cout << "                 개 발 자 : 학번 이름 학번 이름\n\n";
	cout << "          스 페 이 스 바 를   누 르 면   메 인 화 면 으 로   이 동 합 니 다 .";

	while (true) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}

int MatchingGame::GameMode() {
	system("cls");
	int x = 24;
	int y = 6;
	cout << "\n\n";
	cout << "                               [ 난 이 도  선 택 ]\n\n";
	gotoxy(x - 2, y);
	cout << "> Nomal";
	gotoxy(x, y + 1);
	cout << "Crazy";
	gotoxy(x, y + 2);
	cout << "뒤 로";
	while (true) {
		int key = keyControl();
		switch (key)
		{
		case UP: {
			if (y > 6) {
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, --y);
				cout << ">";
			}
			break;
		}
		case DOWN: {
			if (y < 9) {
				gotoxy(x - 2, y);
				cout << " ";
				gotoxy(x - 2, ++y);
				cout << ">";
			}
			break;
		}
		case SUBMIT: {
			return y - 6;
		}
		}
	}


}