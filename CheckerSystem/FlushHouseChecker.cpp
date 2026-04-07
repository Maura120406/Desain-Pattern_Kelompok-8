#include "FlushHouseChecker.h"
#include "FullHouseChecker.h"
#include "FlushChecker.h"

bool FlushHouseChecker::check(const std::vector<Card>& cards) {
    FullHouseChecker fh;
    FlushChecker fl;

    return fh.check(cards) && fl.check(cards);
}