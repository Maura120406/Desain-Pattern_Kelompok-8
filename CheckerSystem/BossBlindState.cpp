#include "BossBlindState.h"
#include "SmallBlindState.h"
#include "BonusHandCommand.h"

std::string BossBlindState::getName() const {
    return "Boss Blind";
}

int BossBlindState::getTargetScore() const {
    return 1000;
}

int BossBlindState::getRewardMoney() const {
    return 500;
}

std::shared_ptr<BlindState>
BossBlindState::nextState() {

    return std::make_shared<SmallBlindState>();
}

std::shared_ptr<RewardCommand>
BossBlindState::createSkipReward() {

    return std::make_shared<BonusHandCommand>();
}