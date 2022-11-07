#include <bits/stdc++.h>
using namespace std;

// APPROACH 1
void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    vector<int> temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
    int x = row;
    int y = col;

    //      CHECK FOR SAME ROW
    while (y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        y--;
    }

    x = row;
    y = col;

    //            CHECK FOR  LOWER DIAGONALS
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        y--;
        x--;
    }

    x = row;
    y = col;

    //            CHECK FOR UPPER DIAGONALS
    while (x < n && y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        y--;
        x++;
    }
    return true;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    //      BASE CASE
    if (col == n)
    {
        addSolution(ans, board, n);
        return;
    }
    //      SOLVE 1 CASE AND REST RECURSIVE WILL TAKE CARE

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            //             IF PLACING QUEEN IS SAFE
            board[row][col] = 1;

            //             RECURSION
            solve(col + 1, ans, board, n);

            //              BACKTRACK
            board[row][col] = 0;
        }
    }
}
vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    solve(0, ans, board, n);

    return ans;
}

// APPROACH 2

#include <unordered_map>

unordered_map<int, bool> roww(false);

unordered_map<int, bool> lower(false);

unordered_map<int, bool> upper(false);

void add(vector<vector<int>> &board, vector<vector<int>> &ans, int n)

{

    vector<int> temp;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {

            temp.push_back(board[i][j]);
        }
    }

    ans.push_back(temp);
}

void solve(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n)

{

    // base case - jab saare col fill ho jaye tb board ke values ko ans mein daalna

    if (col == n)

    {

        add(board, ans, n);
    }

    // saare row ko traverse kro

    for (int row = 0; row < n; row++)

    {

        if (roww[row] == false && lower[row + col] == false && upper[(n - 1) + col - row] == false)

        {

            board[row][col] = 1;

            roww[row] = true;

            lower[row + col] = true;

            upper[(n - 1) + col - row] = true;

            solve(col + 1, board, ans, n);

            // Backtrack

            board[row][col] = 0;

            roww[row] = false;

            lower[row + col] = false;

            upper[(n - 1) + col - row] = false;
        }
    }
}

vector<vector<int>> nQueens(int n)

{

    vector<vector<int>> board(n, vector<int>(n, 0));

    vector<vector<int>> ans;

    int col = 0;

    solve(col, board, ans, n);

    return ans;
}