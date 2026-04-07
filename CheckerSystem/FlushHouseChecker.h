#pragma once
#include <vector>
#include "Card.h"

class FlushHouseChecker {
public:
    bool check(const std::vector<Card>& cards);
};