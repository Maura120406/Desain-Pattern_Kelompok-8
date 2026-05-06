#pragma once
#include <string>

class Card {
public:
    int rank;
    std::string suit;

    Card(int r, std::string s) : rank(r), suit(s) {}

    Card() : rank(0), suit("") {}
};