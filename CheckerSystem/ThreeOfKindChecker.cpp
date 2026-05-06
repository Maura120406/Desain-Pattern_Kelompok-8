#include "ThreeOfKindChecker.h"
#include <map>

bool ThreeOfKindChecker::check(const std::vector<Card>& cards) {
    std::map<int, int> count;

    for (auto& c : cards)
        count[c.rank]++;

    for (auto& r : count)
        if (r.second == 3)
            return true;

    return false;
}