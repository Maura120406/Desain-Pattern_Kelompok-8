#include <iostream>
#include "HandPlayer.h"

void HandPlayer::setHand(
    const std::vector<Card>& cards
) {
    hand = cards;
}

void HandPlayer::playHand() {

    std::cout << "Your cards:\n";

    for (int i = 0; i < hand.size(); i++) {

        std::cout
            << i + 1 << ": "
            << hand[i].rank
            << hand[i].suit
            << "\n";
    }

    std::cout
        << "Pilih 5 kartu (masukkan index):\n";

    selected.clear();

    for (int i = 0; i < 5; i++) {

        int idx;

        std::cout
            << "Pilih kartu ke-"
            << i + 1
            << ": ";

        std::cin >> idx;

        if (idx >= 1 &&
            idx <= hand.size()) {

            selected.push_back(
                hand[idx - 1]
            );
        }
    }
}

std::vector<Card>
HandPlayer::getSelectedHand() const {

    return selected;
}