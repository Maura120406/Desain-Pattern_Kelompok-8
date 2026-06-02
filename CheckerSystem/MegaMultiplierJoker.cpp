#include "MegaMultiplierJoker.h"

void MegaMultiplierJoker::apply(ScoreContext& context) {
    context.scoreMultiplier += 5;
}

const char* MegaMultiplierJoker::getName() const {
    return "Mega Multiplier Joker";
}