#include <bits/stdc++.h>
using namespace std;







int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool search_dfs(int x, int y, int index, vector<string> &matrix, string &target, int &row, int &column)
{
    // reached the destination
    if (index == target.size() - 1)
        return true;

    index++;
    //explore all 4 direction
    for (int i = 0; i < 4; i++)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];

        // inside boundary and matched character
        if (newX >= 0 && newY >= 0 && newX < row && newY < column && matrix[newX][newY] == target[index])
        {
            if (search_dfs(newX, newY, index, matrix, target, row, column))
                return true;
        }
    }
    // no match
    return false;
}
int exist(vector<string> &matrix, string target)
{
    // if target is empty
    if (target == "")
        return 1;
    int row = matrix.size();
    if (row == 0)
        return 0;
    int column = matrix[0].size();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            // if first index matched
            if (matrix[i][j] == target[0])
            {
                if (search_dfs(i, j, 0, matrix, target, row, column))
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}







/*
  T(n)= 4*T(n-1)+1 = O(4^n)

  Time Complexity: O(4^(row*column))
  space Complexity: O(row* column)
*/