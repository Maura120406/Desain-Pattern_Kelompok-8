#pragma once

#include <memory>
#include <vector>

class BlindState;
class RewardCommand;

class RuntimeSession {
public:

    int ante;
    int totalScore;
    int money;

    int remainingHands;
    int remainingDiscards;

    std::shared_ptr<BlindState>
        currentBlind;

    std::vector<
        std::shared_ptr<RewardCommand>
    > pendingCommands;

    RuntimeSession();
};