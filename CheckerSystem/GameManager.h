#pragma once
#include "HandGenerator.h"
#include "HandPlayer.h"
#include "ScoringRule.h"
#include "BlindRule.h"
#include "RewardRule.h"
#include "JokerManager.h"
#include "JokerEvaluator.h"
#include "RuntimeSession.h"

class GameManager {
public:
    void run();
    void playRound();

private:
    HandGenerator handGenerator;
    HandPlayer handPlayer;
    ScoringRule scoringRule;
    BlindRule blindRule;
    RewardRule rewardRule;
    JokerManager jokerManager;
    RuntimeSession session;
};