#include <iostream>
#include <string>
#include <vector>

#define BOARD_SIZE 8

inline bool attackedByBishop(const std::vector<std::string>& board,
                             const int i, const int j)
{
    // Up right
    for (int row = i - 1, col = j + 1; row >= 0 && col < BOARD_SIZE; row--, col++)
    {
        if (board[row][col] == '*')
            continue;
        else if (board[row][col] == 'B')
            return true;
        else
            break;
    }
    // Up left
    for (int row = i - 1, col = j - 1; row >= 0 && col >= 0; row--, col--)
    {
        if (board[row][col] == '*')
            continue;
        else if (board[row][col] == 'B')
            return true;
        else
            break;
    }
    // Down right
    for (int row = i + 1, col = j + 1; row < BOARD_SIZE && col < BOARD_SIZE; row++, col++)
    {
        if (board[row][col] == '*')
            continue;
        else if (board[row][col] == 'B')
            return true;
        else
            break;
    }
    // Down left
    for (int row = i + 1, col = j - 1; row < BOARD_SIZE && col >= 0; row++, col--)
    {
        if (board[row][col] == '*')
            continue;
        else if (board[row][col] == 'B')
            return true;
        else
            break;
    }

    return false;
}


inline bool attackedByRook(const std::vector<std::string>& board, const int i, const int j)
{
    // Down
    for (int row = i + 1; row < BOARD_SIZE; row++)
    {
        if (board[row][j] == '*')
            continue;
        else if (board[row][j] == 'R')
            return true;
        else
            break;
    }
    // Up
    for (int row = i - 1; row >= 0; row--)
    {
        if (board[row][j] == '*')
            continue;
        else if (board[row][j] == 'R')
            return true;
        else
            break;
    }
    // Right
    for (int col = j + 1; col < BOARD_SIZE; col++)
    {
        if (board[i][col] == '*')
            continue;
        else if (board[i][col] == 'R')
            return true;
        else
            break;
    }
    // Left
    for (int col = j - 1; col >= 0; col--)
    {
        if (board[i][col] == '*')
            continue;
        else if (board[i][col] == 'R')
            return true;
        else
            break;
    }
    return false;
}

int main()
{
    std::vector<std::string> board(BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        std::cin >> board[i];
    }

    int unattacked = BOARD_SIZE * BOARD_SIZE;

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] != '*')
            {
                unattacked--;
            }
            else if (attackedByRook(board, i, j) || attackedByBishop(board, i, j))
            {
                unattacked--;
            }
        }
    }

    std::cout << unattacked << '\n';

    return 0;
}