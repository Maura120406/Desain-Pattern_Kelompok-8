#include "BonusHandCommand.h"
#include "RuntimeSession.h"

void BonusHandCommand::execute(
    RuntimeSession& session
) {
    session.remainingHands++;
}