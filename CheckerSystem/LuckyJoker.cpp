#include "LuckyJoker.h"

void LuckyJoker::apply(ScoreContext& context) {
    context.bonusChips += 100;
}

const char* LuckyJoker::getName() const {
    return "Lucky Joker";
}