#pragma once
#include "ScoreContext.h"

class Joker {
public:
    virtual void apply(ScoreContext& context) = 0;
};