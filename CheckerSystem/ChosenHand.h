#pragma once
#include <vector>
#include "Card.h"
#include "HandState.h"

class ChosenHand {
private:
    std::vector<Card> selectedCards;

public:
    ChosenHand(const HandState& handState,
        const std::vector<int>& indices);

    const std::vector<Card>& getCards() const;
};