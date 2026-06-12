#include "RuntimeSession.h"
#include "SmallBlindState.h"

RuntimeSession::RuntimeSession() {

    ante = 1;

    totalScore = 0;

    money = 0;

    remainingHands = 4;

    remainingDiscards = 3;

    currentBlind =
        std::make_shared<
        SmallBlindState>();
}