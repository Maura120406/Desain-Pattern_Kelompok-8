#include "StraightChecker.h"
#include <vector>
#include <algorithm>

bool StraightChecker::check(const std::vector<Card>& cards) {
    std::vector<int> ranks;

    for (auto& c : cards)
        ranks.push_back(c.rank);

    std::sort(ranks.begin(), ranks.end());

    for (int i = 0; i < ranks.size() - 1; i++) {
        if (ranks[i] + 1 != ranks[i + 1])
            return false;
    }

    return true;
}