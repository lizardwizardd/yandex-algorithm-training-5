#include <iostream>
#include <unordered_map>

int main()
{
    int n, maxRange;
    std::cin >> n >> maxRange;

    std::unordered_map<int, int> lastIndex;
    for (int i = 0; i < n; i++)
    {
        int num;
        std::cin >> num;

        if (lastIndex.find(num) == lastIndex.end()) // first occurrence
        {
            lastIndex[num] = i; // update last index
        }
        else
        {
            if (i - lastIndex[num] <= maxRange)
            {
                std::cout << "YES" << '\n';
                return 0;
            }
            else
            {
                lastIndex[num] = i;
            }
        }
    }

    std::cout << "NO" << '\n';
    
    return 0;
}