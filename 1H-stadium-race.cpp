#include <iostream>

int main()
{
    int L;
    int x1, x2;
    int v1, v2;
    std::cin >> L >> x1 >> v1 >> x2 >> v2;

    double res = 99999999999;

    int deltaX = (x2 - x1 + L) % L;
    int deltaV = v1 - v2;
    if (deltaV < 0)
    {
        deltaV = -deltaV;
        deltaX = (-deltaX + L ) % L;
    }
    if (deltaX == 0)
        res = 0; // already at the same distance
    if (deltaV != 0)
    {
        double time = (double)deltaX / deltaV;
        if (time < res)
            res = time;
    }

    // Mirror the 2nd runner and do the same calculations
    x2 = (-1 * x2 + L) % L;
    v2 = -v2;
    deltaX = (x2 - x1 + L) % L;
    deltaV = v1 - v2;
    if (deltaV < 0)
    {
        deltaV = -deltaV;
        deltaX = (-deltaX + L ) % L;
    }
    if (deltaX == 0)
        res = 0; // already at the same distance
    if (deltaV != 0)
    {
        double time = (double)deltaX / deltaV;
        if (time < res)
            res = time;
    }
    
    if (res == 99999999999)
        std::cout << "NO\n";
    else
    {
        std::cout << "YES\n";
        printf("%.10f\n", res);
    }

    return 0;
}