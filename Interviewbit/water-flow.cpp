#include <bits/stdc++.h>
using namespace std;









int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(queue<pair<int, int>> &q, vector<vector<bool>> &visited, int &row, int &column, vector<vector<int>> &matrix)
{

    while (!q.empty())
    {
        //get both x and y coordinates
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // explore 4 directions
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];

            // voilate boundary condition or lake is already visited
            if (newX < 0 || newY < 0 || newX >= row || newY >= column || visited[newX][newY] == true)
                continue;

            // lake flow from lower to higher heights according to questions
            if (matrix[x][y] <= matrix[newX][newY])
            {
                q.push({newX, newY});
                visited[newX][newY] = true;
            }
        }
    }
}
int solve(vector<vector<int>> &matrix)
{

    int row = matrix.size();
    if (row == 0)
        return 0;
    int column = matrix[0].size();

    // to check lake touched or not
    vector<vector<bool>> blue_visited(row, vector<bool>(column, false));
    vector<vector<bool>> red_visited(row, vector<bool>(column, false));

    //do multilevel queue
    queue<pair<int, int>> qBlue, qRed;

    // store blue and red lake touched index in respective queue
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (i == 0 || j == 0)
            {
                qBlue.push({i, j});
                blue_visited[i][j] = true;
            }
            if (i == row - 1 || j == column - 1)
            {
                qRed.push({i, j});
                red_visited[i][j] = true;
            }
        }
    }

    // explore all possible cell that touched
    bfs(qBlue, blue_visited, row, column, matrix);
    bfs(qRed, red_visited, row, column, matrix);

    // get the result if both lake touched
    int ans = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (blue_visited[i][j] && red_visited[i][j])
            {
                ans++;
            }
        }
    }

    return ans;
}


/*


  Time Complexity: O(m*n)
  Space Complexity: O(m*n)


*/