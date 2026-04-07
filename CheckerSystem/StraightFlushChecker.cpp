#include "StraightFlushChecker.h"
#include "StraightChecker.h"
#include "FlushChecker.h"

bool StraightFlushChecker::check(const std::vector<Card>& cards) {
    StraightChecker s;
    FlushChecker f;

    return s.check(cards) && f.check(cards);
}