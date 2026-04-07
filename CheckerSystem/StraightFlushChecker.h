#pragma once
#include <vector>
#include "Card.h"

class StraightFlushChecker {
public:
    bool check(const std::vector<Card>& cards);
};