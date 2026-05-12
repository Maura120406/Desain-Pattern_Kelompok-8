#include <iostream>
#include "GameManager.h"
#include "HandEvaluator.h"
#include "MultiplierJoker.h"
#include "ScoreContext.h"
#include "PlayerHandResult.h"
#include "HandState.h"

void GameManager::run() {
    std::cout << "=== GAME START ===\n";

    std::vector<Card> hand = handGenerator.generateHand();

    handPlayer.setHand(hand);
    handPlayer.playHand();

    std::vector<Card> selected = handPlayer.getSelectedHand();

    std::string result = HandEvaluator::evaluate(selected);

    std::cout << "Combination: " << result << std::endl;

    int baseScore = scoringRule.scoreHand(result);

    PlayerHandResult playedResult(
        result,
        baseScore
    );

    ScoreContext context;
    MultiplierJoker joker;
    joker.apply(context);
    int finalScore =
        (playedResult.getBaseScore()
            + context.bonusChips)
        * context.scoreMultiplier;
    std::cout << "Multiplier: "
        << context.scoreMultiplier
        << std::endl;

    std::cout << "Final Score: "
        << finalScore
        << std::endl;

    bool win = blindRule.checkBlind(finalScore);

    int reward =
        rewardRule.earnMoney(
            win,
            finalScore
        );
    std::cout << "Money gained: " << reward << std::endl;

    std::cout << "\nDiscard 2 kartu.\n";

    std::vector<int> discardIndices = { 0, 1 };

    std::vector<Card> newCards =
        handGenerator.drawCards(2);

    HandState handState(hand);

    handState.discardAndRedraw(
        discardIndices,
        newCards
    );

    std::cout << "New Hand:\n";

    for (const auto& card : handState.getCards()) {
        std::cout
            << card.rank
            << card.suit
            << " ";
    }

    std::cout << std::endl;

    std::cout << "=== GAME END ===\n";
}