#include <iostream>
#include "HandPlayer.h"

void HandPlayer::setHand(const std::vector<Card>& cards) {
    hand = cards;
}

void HandPlayer::playHand() {
    std::cout << "Your cards:\n";

    for (int i = 0; i < hand.size(); i++) {
        std::cout << i << ": " << hand[i].rank << hand[i].suit << "\n";
    }

    std::cout << "Pilih 5 kartu (masukkan index):\n";

    selected.clear();

    for (int i = 0; i < 5; i++) {
        int idx;
        std::cin >> idx;

        if (idx >= 0 && idx < hand.size()) {
            selected.push_back(hand[idx]);
        }
    }
}

std::vector<Card> HandPlayer::getSelectedHand() const {
    return selected;
}