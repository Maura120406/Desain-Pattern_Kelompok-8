#include "FlushChecker.h"

bool FlushChecker::check(const std::vector<Card>& cards) {
    std::string suit = cards[0].suit;

    for (auto& c : cards)
        if (c.suit != suit)
            return false;

    return true;
}