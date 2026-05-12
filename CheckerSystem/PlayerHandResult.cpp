#include "PlayerHandResult.h"

PlayerHandResult::PlayerHandResult(
    const std::string& hand,
    int score
)
    : handName(hand),
    baseScore(score) {
}

std::string PlayerHandResult::getHandName() const {
    return handName;
}

int PlayerHandResult::getBaseScore() const {
    return baseScore;
}