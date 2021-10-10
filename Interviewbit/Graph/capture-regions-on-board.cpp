#include <bits/stdc++.h>
using namespace std;







void solve(vector<vector<char>> &matrix)
{
    int row = matrix.size();
    if (row == 0)
        return;
    int column = matrix[0].size();

    // store all boundary 'O'
    queue<pair<int, int>> q;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (matrix[i][j] == 'O' && (i == 0 || j == 0 || i == row - 1 || j == column - 1))
            {
                q.push({i, j});
                matrix[i][j] = '^';
            }
        }
    }

    // all four direction move
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    // multisource BFS using queue
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // explore all four direction
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];

            // inside boundary and it is 'O'
            if (newX >= 0 && newY >= 0 && newX < row && newY < column && matrix[newX][newY] == 'O')
            {
                q.push({newX, newY});
                matrix[newX][newY] = '^';
            }
        }
    }

    // change ('O' to 'X') and ('^' to 'O')
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (matrix[i][j] == '^')
            {
                matrix[i][j] = 'O';
            }
            else if (matrix[i][j] == 'O')
            {
                matrix[i][j] = 'X';
            }
        }
    }
}







/*
  Time Complexity: O(n*m)
  Space Complexity: O(n*m)
*/