#include <iostream>

int main()
{
    int k;
    std::cin >> k;

    int maxX = 0;
    int minX = 99999999999;
    int maxY = 0;
    int minY = 99999999999;

    while (k--)
    {
        int x, y;
        std::cin >> x >> y;

        maxX = std::max(maxX, x);
        minX = std::min(minX, x);
        maxY = std::max(maxY, y);
        minY = std::min(minY, y);
    }

    std::cout << minX << ' ' << minY << ' ' << maxX << ' ' << maxY << '\n';
    
    return 0;
}