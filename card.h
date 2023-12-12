#ifndef CARD_H
#define CARD_H

struct Card {
    char value; // ī���� ��
    bool matched; // ��Ī�� �������� ����
    bool selected; // ���� ���õ� �������� ����

    Card() : value('0'), matched(false), selected(false) {}
    Card(char val) : value(val), matched(false), selected(false) {}
};

#endif // CARD_H
