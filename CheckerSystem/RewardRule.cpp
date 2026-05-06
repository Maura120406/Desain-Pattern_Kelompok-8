#include "RewardRule.h"

int RewardRule::earnMoney(bool win, int score) {
    return win ? score * 2 : score / 2;
}