
#include "ChosenHand.h"

ChosenHand::ChosenHand(
    const HandState& handState,
    const std::vector<int>& indices
) {
    const auto& cards = handState.getCards();

    for (int idx : indices) {
        selectedCards.push_back(cards[idx]);
    }
}

const std::vector<Card>& ChosenHand::getCards() const {
    return selectedCards;
}