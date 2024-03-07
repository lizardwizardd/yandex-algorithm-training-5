#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> lengths(n);

    int uncutStringLength = -1;
    for (int i = 0; i < n; i++)
    {
        std::cin >> lengths[i];

        if (lengths[i] > uncutStringLength)
        {
            // Assuming that the longest string is the uncut one
            uncutStringLength = lengths[i];
        }
    }

    // Don't count the uncut string
    int cutStringLength = -1 * uncutStringLength;
    for (int i = 0; i < n; i++)
    {
        cutStringLength += lengths[i];
    }

    
    if (uncutStringLength - cutStringLength <= 0)
    {
        // Uncut string was taken
        std::cout << uncutStringLength + cutStringLength << '\n';
    }
    else
    {
        std::cout << uncutStringLength - cutStringLength << '\n';
    }


    return 0;
}