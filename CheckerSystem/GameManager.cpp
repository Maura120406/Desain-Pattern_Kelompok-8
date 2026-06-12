#include <iostream>
#include <algorithm>

#include "GameManager.h"
#include "HandEvaluator.h"
#include "ScoreContext.h"
#include "PlayerHandResult.h"
#include "HandState.h"
#include "JokerManager.h"
#include "JokerEvaluator.h"
#include "RuntimeSession.h"
#include "BlindState.h"
#include "RewardCommand.h"

void GameManager::run()
{
    bool playing = true;

    while (playing)
    {
        playRound();

        char answer;

        std::cout
            << "\nLanjut ke blind berikutnya? (y/n): ";

        std::cin >> answer;

        if (answer != 'y')
        {
            playing = false;
        }
    }
}

void GameManager::playRound() {

    std::cout << "=== GAME START ===\n";

    std::cout
        << "Current Blind: "
        << session.currentBlind
        ->getName()
        << std::endl;

    std::cout
        << "Target Score: "
        << session.currentBlind
        ->getTargetScore()
        << std::endl;

    std::cout
        << "\n1. Play\n";

    std::cout
        << "2. Skip\n";

    int choice;

    std::cin >> choice;

    // Skip

    if (choice == 2) {

        auto reward =
            session.currentBlind
            ->createSkipReward();

        session.pendingCommands
            .push_back(reward);

        std::cout
            << "Blind Skipped!\n";

        session.currentBlind =
            session.currentBlind
            ->nextState();

        for (auto& cmd :
            session.pendingCommands) {

            cmd->execute(session);
        }

        session.pendingCommands.clear();

        return;
    }

    // Generate Hand
 
    std::vector<Card> hand =
        handGenerator.generateHand();

    handPlayer.setHand(hand);

    handPlayer.playHand();

    // Chosen Hand
  
    std::vector<Card> selected =
        handPlayer.getSelectedHand();

    HandState handState(selected);

    // Show Chosen Hand
  
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

    // Discard
    
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

    // Remove Discarded Cards
  
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

    // Draw Cards

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

    // Choose Redraw Cards

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

    // Build Final Hand
   
    for (const auto& card :
        chosenRedraw) {

        currentHand.push_back(card);
    }

    HandState finalHand(currentHand);

    // Show Final Hand
  
    std::cout << "\nFinal Hand:\n";

    for (const auto& card :
        finalHand.getCards()) {

        std::cout
            << card.rank
            << card.suit
            << " ";
    }

    std::cout << std::endl;

    // Evaluate Final Hand
  
    std::string result =
        HandEvaluator::evaluate(
            finalHand.getCards()
        );

    std::cout
        << "\nCombination: "
        << result
        << std::endl;

    // Base Score
   
    int baseScore =
        scoringRule.scoreHand(result);

    PlayerHandResult playedResult(
        result,
        baseScore
    );

  
    // Joker System


    ScoreContext context;

    jokerManager.chooseJokers();

    JokerEvaluator::applyJokers(
        jokerManager.getSelectedJokers(),
        context
    );


    // Final Score
  

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

  
    // Reward
   

    bool win =
        finalScore >=
        session.currentBlind
        ->getTargetScore();

    int reward =
        rewardRule.earnMoney(
            win,
            finalScore
        );
    session.money += reward;

    if (win) {

        std::cout
            << "Blind Cleared!\n";

        session.money +=
            session.currentBlind
            ->getRewardMoney();

        session.currentBlind =
            session.currentBlind
            ->nextState();
    }

    if (!session.pendingCommands.empty()) {

        std::cout
            << "\nExecuting Rewards...\n";

        for (auto& cmd :
            session.pendingCommands) {

            cmd->execute(
                session
            );
        }

        session.pendingCommands.clear();
    }

    std::cout
        << "Money: "
        << session.money
        << std::endl;

    std::cout
        << "Bonus Chips: "
        << context.bonusChips
        << std::endl;

    std::cout
        << "Multiplier: "
        << context.scoreMultiplier
        << std::endl;

    std::cout
        << "Remaining Hands: "
        << session.remainingHands
        << std::endl;

    std::cout
        << "Remaining Discards: "
        << session.remainingDiscards
        << std::endl;

    std::cout
        << "Next Blind: "
        << session.currentBlind
        ->getName()
        << std::endl;

    std::cout
        << "=== GAME END ===\n";
}