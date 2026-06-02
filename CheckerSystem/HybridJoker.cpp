#include "HybridJoker.h"

void HybridJoker::apply(ScoreContext& context) {
    context.bonusChips += 50;
    context.scoreMultiplier += 1;
}

const char* HybridJoker::getName() const {
    return "Hybrid Joker";
}