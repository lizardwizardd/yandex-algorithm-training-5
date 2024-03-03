#include <iostream>

int main()
{
    int P, V, Q, M;
    std::cin >> P >> V >> Q >> M;

    int PLeft = P - V; 
    int PRight = P + V;
    int MLeft = Q - M;
    int MRight = Q + M;

    int intersection = std::min(PRight, MRight) - std::max(PLeft, MLeft) + 1;
    if (intersection < 0)
        intersection = 0;

    std::cout << (PRight - PLeft + 1) + (MRight - MLeft + 1) - intersection;

    return 0;
}