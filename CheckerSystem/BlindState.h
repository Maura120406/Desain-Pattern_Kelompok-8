#pragma once
#include <string>
#include <memory>

class RewardCommand;
class BlindState;

class BlindState {
public:

    virtual ~BlindState() = default;

    virtual std::string getName() const = 0;

    virtual int getTargetScore() const = 0;

    virtual int getRewardMoney() const = 0;

    virtual std::shared_ptr<BlindState>
        nextState() = 0;

    virtual std::shared_ptr<RewardCommand>
        createSkipReward() = 0;
};