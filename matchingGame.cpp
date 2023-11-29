#include "MatchingGame.h"
#include "Control.h"
#include <iostream>

MatchingGame::MatchingGame() : difficulty("Normal") {}

void MatchingGame::startGame() {
	while (true) {
		GameName();
		int menuKey = menuDraw();
		if (menuKey == 0) {//���ӽ���
			int GameModeKey = GameMode();
			if (GameModeKey == 0) { // �븻

			}
			else if (GameModeKey == 1) { // ũ������

			}
			// GameModeKey == 2 �� �ڷΰ���Ƿ� if�� Ż��
		}
		else if (menuKey == 1) {//���� ���
			GameInfo();
		}
		else if (menuKey == 2) {
			return; // ���� ����
		}
		system("cls");
	}

	system("cls"); // ȭ�� �ʱ�ȭ



	//selectDifficulty();
	//if (difficulty == "Normal") {
	//    playNormal();
	//}
	//else if (difficulty == "Crazy") {
	//    playCrazy();
	//}
}

//void MatchingGame::selectDifficulty() {
//    std::cout << "���̵��� �����ϼ���. (Normal/Crazy): ";
//    std::cin >> difficulty;
//}
//
//void MatchingGame::playNormal() {
//    std::cout << "�븻 ��带 �����ϼ̽��ϴ�. ������ �����մϴ�.\n";
//    // ���⿡ Normal ����� ���� ������ �����ϼ���.
//}
//
//void MatchingGame::playCrazy() {
//    std::cout << "Crazy��带 �����ϼ̽��ϴ�. ������ �����մϴ�.\n";
//    // ���⿡ Crazy ����� ���� ������ �����ϼ���.
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