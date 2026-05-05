#include <iostream>
#include "GameManager.h"
#include "HandEvaluator.h"

void GameManager::run() {
    std::cout << "=== GAME START ===\n";

    std::vector<Card> hand = handGenerator.generateHand();

    handPlayer.setHand(hand);
    handPlayer.playHand();

    std::vector<Card> selected = handPlayer.getSelectedHand();

    std::string result = HandEvaluator::evaluate(selected);

    std::cout << "Combination: " << result << std::endl;

    int score = scoringRule.scoreHand(result);
    std::cout << "Score: " << score << std::endl;

    bool win = blindRule.checkBlind(score);

    int reward = rewardRule.earnMoney(win, score);
    std::cout << "Money gained: " << reward << std::endl;

    std::cout << "=== GAME END ===\n";
}