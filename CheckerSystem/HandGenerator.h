#pragma once
#include <vector>
#include "Card.h"

class HandGenerator {
public:
    std::vector<Card> generateHand();
    std::vector<Card> drawCards(int amount);
};