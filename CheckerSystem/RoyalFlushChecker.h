#pragma once
#include <vector>
#include "Card.h"

class RoyalFlushChecker {
public:
    bool check(const std::vector<Card>& cards);
};