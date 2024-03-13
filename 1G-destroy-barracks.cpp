#include <iostream>
#include <cmath>

int roundsToWin(int tgt, int myUnits, int barracksHp, int enemiesPerRound)
{
    int rounds = 0;
    int enemyUnits = 0;

    // Hit units, then barracks until enemy barracks have less than tgt HP
    while (barracksHp >= tgt)
    {
        // Must defeat all evemy units each round until tgt HP
        if (enemyUnits >= myUnits)
            return pow(10, 9);
        barracksHp -= myUnits - enemyUnits;
        enemyUnits = 0;

        if (barracksHp >= 0)
            enemyUnits += enemiesPerRound;

        rounds++;
    }
    // Hit only barracks
    while (barracksHp > 0)
    {
        if (myUnits <= 0) // lost
            return pow(10, 9);
        
        if (barracksHp >= myUnits)
            barracksHp -= myUnits;
        else
        {
            enemyUnits -= myUnits - barracksHp;
            barracksHp = 0;
        }

        myUnits -= enemyUnits;

        if (barracksHp > 0)
            enemyUnits += enemiesPerRound;

        rounds++;
    }
    // Try to defeat the remaining units
    while (enemyUnits > 0)
    {
        if (myUnits <= 0) // lost
            return pow(10, 9);
        enemyUnits -= myUnits;
        if (enemyUnits > 0)
            myUnits -= enemyUnits;
        rounds++;
    }

    return rounds;
}

int main()
{
    int myUnits, barracksHp, enemiesPerRound;
    std::cin >> myUnits >> barracksHp >> enemiesPerRound;

    int res = pow(10, 9);
    for (int tgt = 0; tgt < barracksHp + 2; tgt++)
    {
        int rounds = roundsToWin(tgt, myUnits, barracksHp, enemiesPerRound);
        res = std::min(rounds, res);
    }

    if (res == pow(10, 9))
        res = -1;

    std::cout << res << '\n';

    return 0;
}
