#include <iostream>
#include <algorithm>

#include "GameManager.h"
#include "HandEvaluator.h"
#include "ScoreContext.h"
#include "PlayerHandResult.h"
#include "HandState.h"
#include "JokerManager.h"
#include "JokerEvaluator.h"

void GameManager::run() {

    std::cout << "=== GAME START ===\n";

    // =========================
    // Generate Hand
    // =========================

    std::vector<Card> hand =
        handGenerator.generateHand();

    handPlayer.setHand(hand);

    handPlayer.playHand();

    // =========================
    // Chosen Hand
    // =========================

    std::vector<Card> selected =
        handPlayer.getSelectedHand();

    HandState handState(selected);

    // =========================
    // Show Chosen Hand
    // =========================

    std::cout << "\nCurrent Chosen Hand:\n";

    for (int i = 0;
        i < handState.getCards().size();
        i++) {

        std::cout
            << i + 1 << ": "
            << handState.getCards()[i].rank
            << handState.getCards()[i].suit
            << "\n";
    }

    // =========================
    // Discard
    // =========================

    int discardCount;

    std::cout
        << "\nBerapa kartu yang ingin dibuang? ";

    std::cin >> discardCount;

    std::vector<int> discardIndices;

    std::cout
        << "Masukkan index kartu:\n";

    for (int i = 0;
        i < discardCount;
        i++) {

        int idx;

        std::cin >> idx;

        discardIndices.push_back(
            idx - 1
        );
    }

    // =========================
    // Remove Discarded Cards
    // =========================

    std::vector<Card> currentHand =
        handState.getCards();

    std::sort(
        discardIndices.rbegin(),
        discardIndices.rend()
    );

    for (int idx : discardIndices) {

        currentHand.erase(
            currentHand.begin() + idx
        );
    }

    // =========================
    // Draw Cards
    // =========================

    std::vector<Card> redrawCards =
        handGenerator.drawCards(
            discardCount
        );

    std::cout << "\nRedraw Cards:\n";

    for (int i = 0;
        i < redrawCards.size();
        i++) {

        std::cout
            << i + 1 << ": "
            << redrawCards[i].rank
            << redrawCards[i].suit
            << "\n";
    }

    // =========================
    // Choose Redraw Cards
    // =========================

    std::vector<Card> chosenRedraw;

    for (int i = 0;
        i < discardCount;
        i++) {

        int idx;

        std::cout
            << "Pilih redraw card ke-"
            << i + 1
            << ": ";

        std::cin >> idx;

        chosenRedraw.push_back(
            redrawCards[idx - 1]
        );
    }

    // =========================
    // Build Final Hand
    // =========================

    for (const auto& card :
        chosenRedraw) {

        currentHand.push_back(card);
    }

    HandState finalHand(currentHand);

    // =========================
    // Show Final Hand
    // =========================

    std::cout << "\nFinal Hand:\n";

    for (const auto& card :
        finalHand.getCards()) {

        std::cout
            << card.rank
            << card.suit
            << " ";
    }

    std::cout << std::endl;

    // =========================
    // Evaluate Final Hand
    // =========================

    std::string result =
        HandEvaluator::evaluate(
            finalHand.getCards()
        );

    std::cout
        << "\nCombination: "
        << result
        << std::endl;

    // =========================
    // Base Score
    // =========================

    int baseScore =
        scoringRule.scoreHand(result);

    PlayerHandResult playedResult(
        result,
        baseScore
    );

    // =========================
    // Joker System
    // =========================

    ScoreContext context;

    jokerManager.chooseJokers();

    JokerEvaluator::applyJokers(
        jokerManager.getSelectedJokers(),
        context
    );

    // =========================
    // Final Score
    // =========================

    int finalScore =
        (playedResult.getBaseScore()
            + context.bonusChips)
        * context.scoreMultiplier;

    std::cout
        << "Multiplier: "
        << context.scoreMultiplier
        << std::endl;

    std::cout
        << "Final Score: "
        << finalScore
        << std::endl;

    // =========================
    // Reward
    // =========================

    bool win =
        blindRule.checkBlind(finalScore);

    int reward =
        rewardRule.earnMoney(
            win,
            finalScore
        );

    std::cout
        << "Money gained: "
        << reward
        << std::endl;

    std::cout
        << "=== GAME END ===\n";
}