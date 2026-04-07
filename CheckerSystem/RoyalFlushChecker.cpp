#include "RoyalFlushChecker.h"
#include <vector>
#include <algorithm>

bool RoyalFlushChecker::check(const std::vector<Card>& cards) {
    std::vector<int> ranks;
    std::string suit = cards[0].suit;

    for (auto& c : cards) {
        ranks.push_back(c.rank);
        if (c.suit != suit)
            return false;
    }

    std::sort(ranks.begin(), ranks.end());

    std::vector<int> royal = { 10,11,12,13,14 };

    return ranks == royal;
}