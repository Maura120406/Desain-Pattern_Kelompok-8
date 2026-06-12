#include "FreePlayingCardCommand.h"
#include "RuntimeSession.h"

void FreePlayingCardCommand::execute(
    RuntimeSession& session
) {
    session.money += 100;
}