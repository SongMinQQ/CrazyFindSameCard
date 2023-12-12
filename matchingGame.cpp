#include "MatchingGame.h"
#include "CardGame.h"
#include <algorithm> // For std::shuffle
#include <ctime>     // For std::time (seeding shuffle)
#include <cstdlib>
#include <conio.h>

//MatchingGame::MatchingGame() : difficulty("Normal") {}
MatchingGame::MatchingGame() {
	cardGame = nullptr; // �ʱ⿡�� nullptr�� ����
}

void MatchingGame::startGame() {
	while (true) {
		GameName();
		int menuKey = menuDraw();
		if (menuKey == 0) { // ���� ����
			int GameModeKey = GameMode();
			if (GameModeKey == 0) { // �븻
				system("cls");
				// Normal ��� ī�� ���� ��ü ���� �� �ʱ�ȭ
				delete cardGame; // ������ ������ ��ü�� �ִٸ� ����
				cardGame = new CardGame(5, 4, "Normal");
				cardGame->initializeGame();
				cardGame->drawGameBoard();
				waitForInput();
			}
			else if (GameModeKey == 1) { // ũ������
				system("cls");
				// Crazy ��� ī�� ���� ��ü ���� �� �ʱ�ȭ
				delete cardGame;
				cardGame = new CardGame(6, 5, "Crazy");
				cardGame->initializeGame();
				cardGame->drawGameBoard();
				waitForInput();
			}
			// GameModeKey == 2 �� �ڷΰ����̹Ƿ� if�� Ż��
		}
		else if (menuKey == 1) { // ���� ���
			GameInfo();
		}
		else if (menuKey == 2) {
			delete cardGame; // ���� ���� ���� �޸� ����
			return; // ���� ����
		}
		system("cls");
	}

	delete cardGame; // ���������� �޸� ����
	system("cls"); // ȭ�� �ʱ�ȭ
}

void MatchingGame::waitForInput() {
	cout << "\n����Ϸ��� �ƹ� Ű�� ��������...";
	(void)_getch(); // _getch �Լ��� ����ڰ� Ű�� ���� ������ ��ٸ��ϴ�.
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
	cout << "                 �� �� �� : �й� �̸� �й� �̸�\n\n";
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



