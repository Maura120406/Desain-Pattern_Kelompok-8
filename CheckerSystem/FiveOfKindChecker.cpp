#include "FiveOfAKindChecker.h"
#include <map>

bool FiveOfAKindChecker::check(const std::vector<Card>& cards) {
    std::map<int, int> count;

    for (auto& c : cards)
        count[c.rank]++;

    for (auto& r : count)
        if (r.second == 5)
            return true;

    return false;
}