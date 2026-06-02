#pragma once

#include <vector>
#include "Card.h"

class HandPlayer {

private:
    std::vector<Card> hand;
    std::vector<Card> selected;

public:

    void setHand(
        const std::vector<Card>& cards
    );

    void playHand();

    std::vector<Card>
        getSelectedHand() const;
};