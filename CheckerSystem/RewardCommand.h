#pragma once

class RuntimeSession;

class RewardCommand {
public:

    virtual ~RewardCommand() = default;

    virtual void execute(
        RuntimeSession& session
    ) = 0;
};