#include <iostream>
#include <vector>

int main()
{
    int N, K;
    std::cin >> N >> K;
    std::vector<int> prices(N);

    for (int i = 0; i < N; i++)
    {
        std::cin >> prices[i];
    }

    int maxProfit = 0;

    for (int daysKept = 1; daysKept <= K; daysKept++)
        for (int dayBought = 0; dayBought < N - daysKept; dayBought++)
        {
            maxProfit = std::max(maxProfit, prices[dayBought + daysKept] -
                                            prices[dayBought]);
        }

    std::cout << maxProfit << "\n";

    return 0;
}