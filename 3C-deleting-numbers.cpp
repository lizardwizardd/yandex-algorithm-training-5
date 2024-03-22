#include <iostream>
#include <map>

int main()
{
    int numsCount;
    std::map<int, int> nums;
    std::cin >> numsCount;

    for (int i = 0; i < numsCount; i++)
    {
        int num;
        std::cin >> num;
        nums[num]++;
    }

    // No need to delete anything if there is only one number
    if (numsCount == 1 || numsCount == 0)
    {
        std::cout << 0 << '\n';
        return 0;
    }
    
    int current = 0;
    int res = 999999999;
    auto it = nums.begin();
    auto next = std::next(it);
    while (next != nums.end())
    {
        current = numsCount - it->second; // if we choose to leave the current number
        if (next->first == (it->first) + 1) // if the next number is this+1
        {
            current -= next->second;
        }

        res = std::min(res, current);

        it++;
        next++;
    }

    res = std::min(res, numsCount - std::prev(nums.end())->second);
    std::cout << res << '\n';

    return 0;
}