#pragma once

class ScoreContext {
public:
    int scoreMultiplier;
    int bonusChips;

    ScoreContext()
        : scoreMultiplier(1),
        bonusChips(0) {
    }
};