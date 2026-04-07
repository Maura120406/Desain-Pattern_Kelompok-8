#include "PairChecker.h"
#include <map>

bool PairChecker::check(const std::vector<Card>& cards) {
    std::map<int, int> count;

    for (auto& c : cards)
        count[c.rank]++;

    for (auto& r : count)
        if (r.second == 2)
            return true;

    return false;
}