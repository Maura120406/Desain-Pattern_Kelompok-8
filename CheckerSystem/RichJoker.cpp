#include "RichJoker.h"

void RichJoker::apply(ScoreContext& context) {
    context.bonusChips += 200;
}

const char* RichJoker::getName() const {
    return "Rich Joker";
}