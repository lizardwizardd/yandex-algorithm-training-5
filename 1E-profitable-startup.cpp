#include <iostream>
#include <string>

int main()
{
    unsigned long long profit, k;
    int days;
    std::cin >> profit >> k >> days;

    days -= 1;
    profit *= 10;
    int digit = 0;
    for (; digit < 10; digit++)
    {
        if ((profit + digit) % k == 0)
        {
            // If there's a divisor for first number, then for all of the
            // next ones we can multiply both profit and divisor by 10
            profit += digit;
            std::cout << profit;
            while (days > 0)
            {
                std::cout << '0';
                days--;
            }
            return 0;
        }
    }
    std::cout << "-1";
    return 0;
}