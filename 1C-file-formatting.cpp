#include <iostream>

int main()
{
    int lines;
    unsigned long buttonsPressed = 0;
    unsigned long currentSpaces = 0;
    std::cin >> lines;

    while(lines-- > 0)
    {
        std::cin >> currentSpaces;

        while (currentSpaces >= 4)
        {
            currentSpaces -= 4;
            buttonsPressed += 1;
        }

        if (currentSpaces == 3)      buttonsPressed += 2; // tab + backspace
        else if (currentSpaces == 2) buttonsPressed += 2; // space + space
        else if (currentSpaces == 1) buttonsPressed += 1; // space
    }

    std::cout << buttonsPressed;

    return 0;
}