#include <iostream>

#include "JokerManager.h"
#include "MultiplierJoker.h"
#include "BonusJoker.h"

void JokerManager::chooseJokers() {

    std::cout << "\nChoose Joker:\n";
    std::cout << "1. Multiplier Joker\n";
    std::cout << "2. Bonus Joker\n";

    int choice;
    std::cin >> choice;

    if (choice == 1) {
        selectedJokers.push_back(
            new MultiplierJoker()
        );
    }

    if (choice == 2) {
        selectedJokers.push_back(
            new BonusJoker()
        );
    }
}

const std::vector<Joker*>&
JokerManager::getSelectedJokers() const {
    return selectedJokers;
}