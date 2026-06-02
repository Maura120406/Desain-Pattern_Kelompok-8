#pragma once
#include "Joker.h"

class MegaMultiplierJoker : public Joker {
public:
    void apply(ScoreContext& context) override;

    const char* getName() const override;
};