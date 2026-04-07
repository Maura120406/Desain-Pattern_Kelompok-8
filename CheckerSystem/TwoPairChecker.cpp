#include "TwoPairChecker.h"
#include <map>

bool TwoPairChecker::check(const std::vector<Card>& cards) {
    std::map<int, int> count;
    int pair = 0;

    for (auto& c : cards)
        count[c.rank]++;

    for (auto& r : count)
        if (r.second == 2)
            pair++;

    return pair == 2;
}