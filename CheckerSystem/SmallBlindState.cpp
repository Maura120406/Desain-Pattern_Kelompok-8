#include "SmallBlindState.h"
#include "BigBlindState.h"
#include "BonusHandCommand.h"

std::string SmallBlindState::getName() const {
    return "Small Blind";
}

int SmallBlindState::getTargetScore() const {
    return 100;
}

int SmallBlindState::getRewardMoney() const {
    return 100;
}

std::shared_ptr<BlindState>
SmallBlindState::nextState() {

    return std::make_shared<BigBlindState>();
}

std::shared_ptr<RewardCommand>
SmallBlindState::createSkipReward() {

    return std::make_shared<BonusHandCommand>();
}