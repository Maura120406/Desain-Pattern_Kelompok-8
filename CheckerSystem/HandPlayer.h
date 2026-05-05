#pragma once
#include <vector>
#include "Card.h"

class HandPlayer {
public:
    void setHand(const std::vector<Card>& cards);
    void playHand();

    std::vector<Card> getSelectedHand() const;

private:
    std::vector<Card> hand;
    std::vector<Card> selected;
};