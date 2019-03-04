#ifndef __CARD_H
#define __CARD_H

#include <ostream>

class Card {
   public:
    std::string color;
    int number;

    Card() {}

    Card(std::string color, int number) {
        this->color = color;
        this->number = number;
    }

    ~Card() {}

    Card(const Card& other) {
        this->color = other.color;
        this->number = other.number;
    }

    void operator=(const Card& other) {
        this->color = other.color;
        this->number = other.number;
    }

    Card operator+(const Card& other) {
        return Card(this->color, this->number + other.number);
    }

    friend std::ostream& operator<<(std::ostream& out, const Card& card);
};

std::ostream& operator<<(std::ostream& out, const Card& card) {
    out << card.number << " " << card.color << "\n";
    return out;
}

#endif
