#include <iostream>

#include "Card.h"
#include "Hand.h"

using namespace std;

int main() {
    int number_of_rounds;
    cin >> number_of_rounds;

    string color;
    int number;

    list<Card> cards;
    Hand best_hand(0, cards);

    for (int round = 0; round < number_of_rounds; round++) {
        cout << "------------------ ROUND " << round + 1
             << " ------------------------\n";
        list<Card> cards;
        for (int j = 0; j < 10; j++) {
            cin >> color >> number;
            Card card(color, number);
            cards.push_back(card);
        }

        Hand hand(round, cards);
        Card card = hand.get_color_card("red");
        cout << card;

        card = hand.get_color_card("blue");
        cout << card;

        card = hand.get_color_card("green");
        cout << card;

        card = hand.get_color_card("yellow");
        cout << card;

        card = hand.get_color_card("orange");
        cout << card;

        int score = hand.compute_score();
        cout << "TOTAL: " << score << "\n";

        if (hand < best_hand) {
            best_hand = hand;
        }
    }
    cout << best_hand.round_number + 1 << "\n";
}
