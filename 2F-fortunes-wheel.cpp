#include <iostream>
#include <vector>

// This is cursed

int main()
{
    int sectors, minSpeed, maxSpeed, stopSpeed;
    std::cin >> sectors;
    std::vector<int> scores(sectors);
    for (int i = 0; i < sectors; i++)
        std::cin >> scores[i];
    std::cin >> minSpeed >> maxSpeed >> stopSpeed;

    int maxScoreInWheel = 0;
    for (auto x : scores)
        maxScoreInWheel = std::max(x, maxScoreInWheel);

    // First for loop with increment by 1
    int maxScore = 0;
    for (int speed = minSpeed; speed <= stopSpeed + 1 && speed <= maxSpeed; speed += 1)
    {
        if (speed <= stopSpeed)
        {
            maxScore = std::max(maxScore, scores[0]);
            continue;
        }
        int currentSector = ((speed - 1) / stopSpeed) % sectors;
        maxScore = std::max(maxScore, scores[currentSector]);
        if (currentSector != 0)
        {
            // In this case, we end up in different sector if we go left
            maxScore = std::max(maxScore, scores[sectors - currentSector]);
        }

        // If maxScore == maxScoreInWheel, there's no point to continue
        if (maxScore == maxScoreInWheel)
            break;
    }

    // Initial speed must be 1 above stopSpeed if possible
    int initialSpeed = stopSpeed + 1;
    if (initialSpeed < minSpeed || initialSpeed > maxSpeed)
        initialSpeed = minSpeed;

    // Second for loop with increment by stopSpeed for better performance
    for (int speed = initialSpeed; speed <= maxSpeed; speed += stopSpeed)
    {
        if (speed <= stopSpeed)
        {
            maxScore = std::max(maxScore, scores[0]);
            continue;
        }
        int currentSector = ((speed - 1) / stopSpeed) % sectors;
        maxScore = std::max(maxScore, scores[currentSector]);
        if (currentSector != 0)
        {
            // In this case, we end up in different sector if we go left
            maxScore = std::max(maxScore, scores[sectors - currentSector]);
        }

        // If maxScore == maxScoreInWheel, there's no point to continue
        if (maxScore == maxScoreInWheel)
            break;
    }

    std::cout << maxScore;

    return 0;
}