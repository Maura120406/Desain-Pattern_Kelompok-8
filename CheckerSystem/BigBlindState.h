#pragma once

#include "BlindState.h"

class BigBlindState : public BlindState {
public:

    std::string getName() const override;

    int getTargetScore() const override;

    int getRewardMoney() const override;

    std::shared_ptr<BlindState>
        nextState() override;

    std::shared_ptr<RewardCommand>
        createSkipReward() override;
};