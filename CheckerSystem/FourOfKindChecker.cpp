#include "FourOfKindChecker.h"
#include <map>

bool FourOfKindChecker::check(const std::vector<Card>& cards) {
    std::map<int, int> count;

    for (auto& c : cards)
        count[c.rank]++;

    for (auto& r : count)
        if (r.second == 4)
            return true;

    return false;
}