void GameManager::runSession(){
    std::cout << "=== Run Started ===\n";

    handGenerator.generateHand();
    handPlayer.playHand();
  
    std::vector<Card> hand = handPlayer.getHand();

    std::string result = HandEvaluator::evaluate(hand);

    std::cout << "Hand Result: " << result << "\n";

    int score = scoringRule.scoreHand(result);

    bool win = blindRule.checkBlind(score);
    int reward = rewardRule.earnMoney(win, score);

    std::cout << "Money gained: " << reward << "\n";
    std::cout << "=== Run Ended ===\n";
}
