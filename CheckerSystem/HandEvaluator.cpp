#include "HandEvaluator.h"

#include "RoyalFlushChecker.h"
#include "StraightFlushChecker.h"
#include "FourOfKindChecker.h"
#include "FullHouseChecker.h"
#include "FlushChecker.h"
#include "StraightChecker.h"
#include "TwoPairChecker.h"
#include "PairChecker.h"
#include "FiveOfKindChecker.h"
#include "FlushHouseChecker.h"
#include "LowStraightChecker.h"
#include "ThreeOfKindChecker.h"

std::string HandEvaluator::evaluate(const std::vector<Card>& cards) {

    FiveOfAKindChecker five;
    RoyalFlushChecker royal;
    StraightFlushChecker sf;
    FourOfAKindChecker fk;
    FullHouseChecker fh;
    FlushChecker fl;
    StraightChecker st;
    ThreeOfAKindChecker tk;
    TwoPairChecker tp;
    PairChecker p;
    FlushHouseChecker fh2;
    LowStraightChecker low;

    if (five.check(cards)) return "Five of a Kind";
    if (royal.check(cards)) return "Royal Flush";
    if (sf.check(cards)) return "Straight Flush";
    if (fk.check(cards)) return "Four of a Kind";
    if (fh2.check(cards)) return "Flush House";
    if (fh.check(cards)) return "Full House";
    if (fl.check(cards)) return "Flush";
    if (st.check(cards)) return "Straight";
    if (low.check(cards)) return "Low Straight";
    if (tk.check(cards)) return "Three of a Kind";
    if (tp.check(cards)) return "Two Pair";
    if (p.check(cards)) return "Pair";

    return "High Card";
}