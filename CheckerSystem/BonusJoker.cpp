#include "BonusJoker.h"

void BonusJoker::apply(ScoreContext& context) {
    context.bonusChips += 50;
}

const char* BonusJoker::getName() const {
    return "Bonus Joker";
}