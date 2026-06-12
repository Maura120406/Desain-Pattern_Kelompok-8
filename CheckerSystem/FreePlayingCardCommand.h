#pragma once

#include "RewardCommand.h"

class FreePlayingCardCommand
    : public RewardCommand
{
public:

    void execute(
        RuntimeSession& session
    ) override;
};