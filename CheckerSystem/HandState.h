#pragma once
#include <vector>
#include "Card.h"

class HandState {
private:
    std::vector<Card> cards;

public:
    HandState(const std::vector<Card>& initialCards);

    const std::vector<Card>& getCards() const;

    void discardAndRedraw(
        const std::vector<int>& discardIndices,
        const std::vector<Card>& newCards
    );
};