#pragma once
#include "Joker.h"

class BonusJoker : public Joker {
public:
    void apply(ScoreContext& context) override;

    const char* getName() const override;
};