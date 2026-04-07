#include "LowStraightChecker.h"
#include <vector>
#include <algorithm>

bool LowStraightChecker::check(const std::vector<Card>& cards) {
    std::vector<int> ranks;

    for (auto& c : cards)
        ranks.push_back(c.rank);

    std::sort(ranks.begin(), ranks.end());

    std::vector<int> low = { 2,3,4,5,14 };

    return ranks == low;
}