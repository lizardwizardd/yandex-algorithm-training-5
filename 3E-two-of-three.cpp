#include <iostream>
#include <map>

int main()
{
    std::map<int, int> occurrences;

    int listSize;
    for (int i = 0; i < 3; i++)
    {
        std::cin >> listSize;
        
        for (int j = 0; j < listSize; j++)
        {
            int num;
            std::cin >> num;
            if (occurrences[num] >= 0) // count only once per list
                occurrences[num] = -(occurrences[num] + 1); // mark as counted
        }

        // Mark all as not counted
        for (auto& pair : occurrences)
        {
            if (pair.second < 0)
            {
                pair.second *= -1;
            }
        }
    }

    for (const auto& pair : occurrences)
    {
        if (pair.second >= 2)
        {
            std::cout << pair.first << " ";
        }
    }
    std::cout << '\n';

    return 0;
}
