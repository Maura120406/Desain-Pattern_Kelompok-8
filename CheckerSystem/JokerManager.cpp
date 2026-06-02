#include <iostream>

#include "JokerManager.h"
#include "MultiplierJoker.h"
#include "BonusJoker.h"
#include "MultiplierJoker.h"
#include "BonusJoker.h"
#include "LuckyJoker.h"
#include "MegaMultiplierJoker.h"
#include "RichJoker.h"
#include "DoubleJoker.h"
#include "HybridJoker.h"


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

 std::cout << "1. Multiplier Joker\n";
std::cout << "2. Bonus Joker\n";
std::cout << "3. Lucky Joker\n";
std::cout << "4. Mega Multiplier Joker\n";
std::cout << "5. Rich Joker\n";
std::cout << "6. Double Joker\n";
std::cout << "7. Hybrid Joker\n";
}