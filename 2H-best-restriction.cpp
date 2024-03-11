#include <iostream>
#include <vector>

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> strength(n, std::vector<int>(m));

    int maxStrength = 0;
    int maxStrengthI = -1;
    int maxStrengthJ = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> strength[i][j];
            if (strength[i][j] > maxStrength)
            {
                maxStrength = strength[i][j];
                maxStrengthI = i;
                maxStrengthJ = j;
            }
        }
    }

    // Case 1:
    // Restrict row with max strength and find new max strength
    int restrictI1 = maxStrengthI;
    int newMaxStrength1 = 0;
    int newMaxStrengthJ = -1;
    for (int i = 0; i < n; i++)
    {
        if (i == restrictI1)
            continue;
        for (int j = 0; j < m; j++)
        {
            if (strength[i][j] > newMaxStrength1)
            {
                newMaxStrength1 = strength[i][j];
                newMaxStrengthJ = j;
            }
        }
    }


    // Restrict column with new max strength and find case 1 max strength
    newMaxStrength1 = 0;
    int restrictJ1 = newMaxStrengthJ;
    for (int i = 0; i < n; i++)
    {
        if (i == restrictI1)
            continue;
        for (int j = 0; j < m; j++)
        {
            if (j == restrictJ1)
                continue;
            if (strength[i][j] > newMaxStrength1)
            {
                newMaxStrength1 = strength[i][j];
            }
        }
    }

    // Case 2:
    // Restrict column with max strength and find new max strength
    int restrictJ2 = maxStrengthJ;
    int newMaxStrength2 = 0;
    int newMaxStrengthI = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j == restrictJ2)
                continue;
            if (strength[i][j] > newMaxStrength2)
            {
                newMaxStrength2 = strength[i][j];
                newMaxStrengthI = i;
            }
        }
    }

    // Restrict row with new max strength and find case 2 max strength
    newMaxStrength2 = 0;
    int restrictI2 = newMaxStrengthI;
    for (int i = 0; i < n; i++)
    {
        if (i == restrictI2)
            continue;
        for (int j = 0; j < m; j++)
        {
            if (j == restrictJ2)
                continue;
            if (strength[i][j] > newMaxStrength2)
            {
                newMaxStrength2 = strength[i][j];
            }
        }
    }

    // std::cout << "Case 1: " << newMaxStrength1 << '\n';
    // std::cout << "Case 2: " << newMaxStrength2 << '\n';
    // Compare new max strengths of 2 cases
    if (newMaxStrength1 < newMaxStrength2)
    {
        std::cout << restrictI1 + 1 << ' ' << newMaxStrengthJ + 1 << '\n';
    }
    else
    {
        std::cout << newMaxStrengthI + 1 << ' ' << restrictJ2 + 1 << '\n';
    }

    return 0;
}