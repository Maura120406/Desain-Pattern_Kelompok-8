#include "FullHouseChecker.h"
#include <map>

bool FullHouseChecker::check(const std::vector<Card>& cards) {
    std::map<int, int> count;
    bool three = false, two = false;

    for (auto& c : cards)
        count[c.rank]++;

    for (auto& r : count) {
        if (r.second == 3) three = true;
        if (r.second == 2) two = true;
    }

    return three && two;
}