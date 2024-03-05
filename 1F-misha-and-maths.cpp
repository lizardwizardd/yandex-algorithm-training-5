#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<bool> even(n);
    for (int i = 0; i < n; i++)
    {
        int num;
        std::cin >> num;
        if (num % 2 == 0)
            even[i] = true;
        else
            even[i] = false;
    }

    int oddCount = 0;
    for (bool x : even)
    {
        if (!x)
            oddCount++;   
    }

    std::string result(n - 1, '+');
    
    // If oddCount % 2 = 1, then the sum is odd. Do nothing
    if (oddCount % 2 == 1)
    {
        std::cout << result;
        return 0;
    }
    
    // Otherwise, we need to decrease oddCount by 1 
    for (int i = 0; i < n - 1; i++)
    {
        // We do that by odd * even or odd * odd
        if ((!even[i] && !even[i+1]) || (!even[i] && even[i+1]))
        {
            result[i] = 'x';
            break;
        }
    }

    std::cout << result;

    return 0;
}