#ifndef CARD_H
#define CARD_H

struct Card {
    char value; // 카드의 값
    bool matched; // 매칭된 상태인지 여부
    bool selected; // 현재 선택된 상태인지 여부

    Card() : value('0'), matched(false), selected(false) {}
    Card(char val) : value(val), matched(false), selected(false) {}
};

#endif // CARD_H
