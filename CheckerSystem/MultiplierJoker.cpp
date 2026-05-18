#include "MultiplierJoker.h"

void MultiplierJoker::apply(ScoreContext& context) {
    context.scoreMultiplier += 2;
}

const char* MultiplierJoker::getName() const {
    return "Multiplier Joker";
}