#include <iostream>
#include <unordered_map>
#include <string>

int main()
{
    std::string word1, word2;
    std::unordered_map<char, int> letters1, letters2;

    std::cin >> word1 >> word2;

    for (auto c : word1)
        letters1[c]++;

    for (auto c : word2)
        letters2[c]++;

    if (letters1 == letters2)
        std::cout << "YES" << '\n';
    else
        std::cout << "NO" << '\n';

    return 0;
}