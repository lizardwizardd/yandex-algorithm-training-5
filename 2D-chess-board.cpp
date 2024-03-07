#include <iostream>
#include <vector>

#define BOARD_SIZE 8

int main()
{
    std::vector<std::vector<int>> board
        (BOARD_SIZE, std::vector<int>(BOARD_SIZE));
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        std::cin >> x >> y;
        board[x - 1][y - 1] = 1;
    }

    int perimeter = N * 4;

    for (int x = 0; x < BOARD_SIZE; x++)
    {
        for (int y = 0; y < BOARD_SIZE; y++)
        {
            if (board[x][y] == 1)
            {
                // Check cells around the current cell
                if (x > 0 && board[x - 1][y] == 1)
                    perimeter -= 2;
                if (y > 0 && board[x][y - 1] == 1)
                    perimeter -= 2;
                if (x < 7 && board[x + 1][y] == 1)
                    perimeter -= 2;
                if (y < 7 && board[x][y + 1] == 1)
                    perimeter -= 2;
                
                board[x][y] = -1; // mark as checked
            }
        }
    }

    std::cout << perimeter;
    
    return 0;
}