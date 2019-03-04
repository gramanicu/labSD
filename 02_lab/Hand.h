#ifndef __HAND_H
#define __HAND_H

#include <iterator>
#include <list>
#include "Card.h"

class Hand {
   public:
    int round_number;
    int score;
    std::list<Card> cards;

    Hand() {}

    Hand(int round_number, std::list<Card> cards) {
        this->round_number = round_number;
        this->cards = cards;
    }

    ~Hand() {}

    Hand(const Hand& other) {
        this->round_number = other.round_number;
        this->cards = other.cards;
    }

    void operator=(const Hand& other) {
        this->round_number = other.round_number;
        this->cards = other.cards;
    }

    bool operator<(const Hand& other) {
        return (this->round_number < other.round_number);
    }

    bool operator>(const Hand& other) {
        return (this->round_number > other.round_number);
    }

    Card get_color_card(std::string color) {
        int suma = 0;
        for (auto& card : this->cards) {
            if (card.color == color) {
                suma += card.number;
            }
        }
        return Card(color, suma);
    }

    int compute_score() {
        int suma = 0;
        for (auto& card : this->cards) {
            suma += card.number;
        }
        return suma;
    }
};

#endif
