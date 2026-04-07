#pragma once
#include <vector>
#include <string>
#include "Card.h"

class HandEvaluator {
public:
    static std::string evaluate(const std::vector<Card>& cards);
};