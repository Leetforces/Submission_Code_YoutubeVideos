//https://www.youtube.com/watch?v=VSKkW1JsXr0&t=526s

struct Point
{
public:
    int x;
    int y;
};
// R D L U
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int Solution::solve(int row, int column, vector<string> &mat)
{
    string s = "RDLU";

    vector<vector<int>> dist(row, vector<int>(column, INT_MAX - 1));

    deque<Point> dq;
    dq.push_front({0, 0});
    dist[0][0] = 0;

    while (!dq.empty())
    {
        Point currentPoint = dq.front();
        dq.pop_front();

        if (currentPoint.x == row - 1 && currentPoint.y == column - 1)
            return dist[currentPoint.x][currentPoint.y];

        for (int i = 0; i < 4; i++)
        {
            int newx = currentPoint.x + dx[i];
            int newy = currentPoint.y + dy[i];

            int w = 0;
            if (s[i] != mat[currentPoint.x][currentPoint.y])
                w = 1;

            if ((newx>=0 && newy>=0 && newx<row && newy<column) && dist[currentPoint.x][currentPoint.y]+w < dist[newx][newy])
            {
                dist[newx][newy] = dist[currentPoint.x][currentPoint.y] + w;

                if (w == 0)
                    dq.push_front({newx, newy});
                else
                    dq.push_back({newx, newy});
            }
        }
    }

    return dist[row - 1][column - 1];
}
