#pragma once
#include <vector>
#include "Joker.h"

class JokerManager {
private:
    std::vector<Joker*> selectedJokers;

public:
    void chooseJokers();

    const std::vector<Joker*>&
    getSelectedJokers() const;
};