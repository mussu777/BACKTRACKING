#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &board, int val)
{
    for (int i = 0; i < board.size(); i++)
    {
        //    ROW CHECK
        if (board[row][i] == val)
            return false;

        //     COLUMN CHECK
        if (board[i][col] == val)
            return false;

        //   CHECKING 3*3 MATRIX
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
            return false;
    }
    return true;
}

bool solve(vector<vector<int>> &board)
{
    int n = board[0].size();

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            //       CELL EMPTY
            if (board[row][col] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(row, col, board, val))
                    {
                        board[row][col] = val;

                        //     RECURSIVE CALL
                        bool isValid = solve(board);
                        if (isValid)
                            return true;
                        else
                        {
                            //    BACKTRACK
                            board[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }

    return true;
}

void solveSudoku(vector<vector<int>> &sudoku)
{

    solve(sudoku);

}