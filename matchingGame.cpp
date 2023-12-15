#include "MatchingGame.h"
#include "CardGame.h"
#include "Control.h"
#include <conio.h>

void MatchingGame::startGame() {
	init();
	while (true) {
		GameName();
		int menuKey = menuDraw();
		if (menuKey == 0) { // ���� ����
			int GameModeKey = GameMode();
			if (GameModeKey == 0) { // �븻
				playGame("Normal", 5, 4);
			}
			else if (GameModeKey == 1) { // ũ������
				playGame("Crazy", 6, 5);
			}
		}
		else if (menuKey == 1) { // ���� ���
			GameInfo();
		}
		else if (menuKey == 2) { // ���� ����
			delete cardGame;
			return;
		}
		system("cls");
	}
	delete cardGame;
	system("cls");
}

void MatchingGame::playGame(const string& mode, int width, int height) {
	system("cls");

	delete cardGame;  //  ������ ������ ��ü�� �ִٸ� ����,
	cardGame = new CardGame(width, height, mode);
	cardGame->initializeGame();
	cardGame->drawGameBoard();
	cardGame->startTimer();  // Ÿ�̸� ����

	while (!cardGame->isGameOver()) {
		int input = keyControl();  // Ű �Է��� ���� ���� keyControl() ȣ��
		cardGame->handleInput(input);  // �Է� ó��
		system("cls");
		cardGame->drawGameBoard();
	}

	cardGame->setGameClearTime();  // ���� Ŭ���� �ð� ���
	cardGame->endGame();
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
	cout << "> �� �� �� ��";
	gotoxy(x, y + 1);
	cout << "�� �� �� ��";
	gotoxy(x, y + 2);
	cout << "   �� ��   ";
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
	system("cls"); // ȭ�� �ʱ�ȭ
	cout << "\n\n";
	cout << "                                    [ �� �� �� ]\n\n";
	cout << "                         �� �� : W, A, S, D\n";
	cout << "                         �� �� : �� �� �� �� ��\n\n\n\n\n\n\n";
	cout << "                 �� �� �� : 20192346 �۹α� / 20193295 ������\n\n";
	cout << "          �� �� �� �� �� ��   �� �� ��   �� �� ȭ �� �� ��   �� �� �� �� �� .";

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
	cout << "                               [ �� �� ��  �� �� ]\n\n";
	gotoxy(x - 2, y);
	cout << "> Nomal";
	gotoxy(x, y + 1);
	cout << "Crazy";
	gotoxy(x, y + 2);
	cout << "�� ��";
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
			if (y < 8) {
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

void MatchingGame::init() { 
	system("mode con cols=84 lines=30 | title CrazyFindSameCard"); // ȭ�� �ܼ� â ����, �ܼ� title ���� �ڵ�

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0; // 0�� Ŀ�� �����
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

