#pragma once
#include <vector>
#include "Card.h"

class FlushChecker {
public:
    bool check(const std::vector<Card>& cards);
};