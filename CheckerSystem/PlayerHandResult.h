#pragma once
#include <string>

class PlayerHandResult {
private:
    const std::string handName;
    const int baseScore;

public:
    PlayerHandResult(
        const std::string& hand,
        int score
    );

    std::string getHandName() const;

    int getBaseScore() const;
};