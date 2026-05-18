#include "JokerEvaluator.h"

void JokerEvaluator::applyJokers(
    const std::vector<Joker*>& jokers,
    ScoreContext& context
) {
    for (Joker* joker : jokers) {
        joker->apply(context);
    }
}