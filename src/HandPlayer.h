#pragma once
#include <vector>
#include "Card.h"

class HandPlayer {
public:
    void playHand();
    std::vector<Card> getHand() const;

private:
    std::vector<Card> hand;
};
