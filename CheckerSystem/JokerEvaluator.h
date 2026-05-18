#pragma once
#include <vector>

#include "Joker.h"
#include "ScoreContext.h"

class JokerEvaluator {
public:
    static void applyJokers(
        const std::vector<Joker*>& jokers,
        ScoreContext& context
    );
};