#include "DoubleJoker.h"

void DoubleJoker::apply(ScoreContext& context) {
    context.scoreMultiplier *= 2;
}

const char* DoubleJoker::getName() const {
    return "Double Joker";
}