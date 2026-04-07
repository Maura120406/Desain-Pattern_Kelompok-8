#include "ScoringRule.h"

int ScoringRule::scoreHand(const std::string& handName) {

    if (handName == "Five of a Kind") return 300;
    if (handName == "Royal Flush") return 250;
    if (handName == "Straight Flush") return 200;
    if (handName == "Four of a Kind") return 150;
    if (handName == "Flush House") return 130;
    if (handName == "Full House") return 120;
    if (handName == "Flush") return 100;
    if (handName == "Straight") return 80;
    if (handName == "Low Straight") return 70;
    if (handName == "Three of a Kind") return 60;
    if (handName == "Two Pair") return 40;
    if (handName == "Pair") return 20;

    return 10; // High Card
}
