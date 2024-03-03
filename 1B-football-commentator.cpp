#include <iostream>

int main()
{
    int game1Team1, game1Team2, game2Team1, game2Team2, home;
    char tmp;
    std::cin >> game1Team1 >> tmp >> game1Team2 >>
                game2Team1 >> tmp >> game2Team2 >> home;

    int scoreDifference = game1Team2 + game2Team2 - game1Team1 - game2Team1;
    game2Team1 += scoreDifference;
    
    // If team 1 is already winning
    if (scoreDifference < 0)
    {
        std::cout << 0;
        return 1;  
    }

    if (home == 1) // team 1 played first game at home
    {
        if (game1Team2 >= game2Team1)
            scoreDifference += 1; // draw is not enough to win
    }
    else // team 2 played first game at home
    {
        if (game1Team1 <= game2Team2)
            scoreDifference += 1; // draw is not enough to win
    }

    std::cout << scoreDifference;

    return 0;
}