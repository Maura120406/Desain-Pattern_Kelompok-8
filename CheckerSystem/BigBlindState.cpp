#include "BigBlindState.h"
#include "BossBlindState.h"
#include "FreePlayingCardCommand.h"

std::string BigBlindState::getName() const {
    return "Big Blind";
}

int BigBlindState::getTargetScore() const {
    return 600;
}

int BigBlindState::getRewardMoney() const {
    return 200;
}

std::shared_ptr<BlindState>
BigBlindState::nextState() {

    return std::make_shared<BossBlindState>();
}

std::shared_ptr<RewardCommand>
BigBlindState::createSkipReward() {

    return std::make_shared<FreePlayingCardCommand>();
}