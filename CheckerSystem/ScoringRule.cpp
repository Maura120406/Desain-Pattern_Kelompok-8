#include "ScoringRule.h"

int ScoringRule::scoreHand(const std::string& handName) {
    if (handName == "Straight Flush") return 200;
    if (handName == "Four of a Kind") return 150;
    if (handName == "Full House") return 120;
    if (handName == "Flush") return 100;
    if (handName == "Straight") return 80;
    if (handName == "Three of a Kind") return 60;
    if (handName == "Two Pair") return 40;
    if (handName == "Pair") return 20;
    return 10;
}