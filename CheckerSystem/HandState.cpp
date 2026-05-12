#include "HandState.h"

HandState::HandState(
    const std::vector<Card>& initialCards
)
    : cards(initialCards) {
}

const std::vector<Card>& HandState::getCards() const {
    return cards;
}

void HandState::discardAndRedraw(
    const std::vector<int>& discardIndices,
    const std::vector<Card>& newCards
) {
    for (int i = 0; i < discardIndices.size(); i++) {
        cards[discardIndices[i]] = newCards[i];
    }
}