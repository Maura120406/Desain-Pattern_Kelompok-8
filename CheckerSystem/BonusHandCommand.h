#pragma once

#include "RewardCommand.h"

class BonusHandCommand
    : public RewardCommand
{
public:

    void execute(
        RuntimeSession& session
    ) override;
};