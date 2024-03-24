#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>

int main()
{
    std::unordered_set<std::string> replaceMap;

    std::string newString;
    std::getline(std::cin, newString); // get replacements
    std::istringstream iss(newString);

    std::string word;
    while (iss >> word)
        replaceMap.insert(word);

    std::getline(std::cin, newString); // get words
    iss = std::istringstream(newString);

    while (iss >> word)
    {
        std::string currentWord = "";
        bool replaced = false;

        for (char c : word) // go through each character
        {
            currentWord += c;
            if (replaceMap.find(currentWord) != replaceMap.end())
            {
                replaced = true;
                std::cout << currentWord << ' ';
                break;
            }
        }

        if (!replaced)
        {
            std::cout << word << ' ';
        }
    }

    return 0;
}