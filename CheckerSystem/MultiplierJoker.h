#pragma once
#include "Joker.h"

class MultiplierJoker : public Joker {
public:
    void apply(ScoreContext& context) override;
};