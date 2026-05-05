#include "HandGenerator.h"
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

std::vector<Card> HandGenerator::generateHand() {
    std::vector<Card> deck;

    std::vector<std::string> suits = { "H", "D", "C", "S" };

    for (int rank = 2; rank <= 14; rank++) {
        for (const auto& suit : suits) {
            deck.push_back(Card(rank, suit));
        }
    }

    std::shuffle(deck.begin(), deck.end(), std::default_random_engine(std::time(0)));
  
    std::vector<Card> hand(deck.begin(), deck.begin() + 8);

    return hand;
}