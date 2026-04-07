#include <iostream>
#include "HandPlayer.h"

void HandPlayer::playHand()
{
    std::cout << "Player selects cards...\n";

    // sementara dummy (nanti dari generator)
    hand = {
        Card(10,"H"),
        Card(11,"H"),
        Card(12,"H"),
        Card(13,"H"),
        Card(14,"H")
    };
}

std::vector<Card> HandPlayer::getHand() const {
    return hand;
}
