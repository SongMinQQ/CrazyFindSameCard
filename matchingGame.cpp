#include "MatchingGame.h"
#include "CardGame.h"
#include <algorithm> // For std::shuffle
#include <ctime>     // For std::time (seeding shuffle)
#include <cstdlib>
#include <conio.h>

//MatchingGame::MatchingGame() : difficulty("Normal") {}
MatchingGame::MatchingGame() {
	cardGame = nullptr; // 초기에는 nullptr로 설정
}

void MatchingGame::startGame() {
	while (true) {
		GameName();
		int menuKey = menuDraw();
		if (menuKey == 0) { // 게임 시작
			int GameModeKey = GameMode();
			if (GameModeKey == 0) { // 노말
				system("cls");
				// Normal 모드 카드 게임 객체 생성 및 초기화
				delete cardGame; // 이전에 생성된 객체가 있다면 삭제
				cardGame = new CardGame(5, 4, "Normal");
				cardGame->initializeGame();
				cardGame->drawGameBoard();
				waitForInput();
			}
			else if (GameModeKey == 1) { // 크레이지
				system("cls");
				// Crazy 모드 카드 게임 객체 생성 및 초기화
				delete cardGame;
				cardGame = new CardGame(6, 5, "Crazy");
				cardGame->initializeGame();
				cardGame->drawGameBoard();
				waitForInput();
			}
			// GameModeKey == 2 는 뒤로가기이므로 if문 탈출
		}
		else if (menuKey == 1) { // 게임 방법
			GameInfo();
		}
		else if (menuKey == 2) {
			delete cardGame; // 게임 종료 전에 메모리 정리
			return; // 게임 종료
		}
		system("cls");
	}

	delete cardGame; // 마지막으로 메모리 정리
	system("cls"); // 화면 초기화
}

void MatchingGame::waitForInput() {
	cout << "\n계속하려면 아무 키나 누르세요...";
	(void)_getch(); // _getch 함수는 사용자가 키를 누를 때까지 기다립니다.
}

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



