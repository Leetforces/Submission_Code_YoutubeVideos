#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(vector<int> &a, vector<int> &b, vector<vector<int>> &c);
};

int find(int src, vector<int> &parent)
{
    if (src == parent[src])
        return src;
    else
        return parent[src] = find(parent[src], parent);
}

void union_(int x, int y, vector<int> &parent, vector<int> &rank)
{
    int parent_x = find(x, parent);
    int parent_y = find(y, parent);

    if (rank[parent_x] > rank[parent_y])
    {
        parent[parent_y] = parent_x;
    }
    else if (rank[parent_x] < rank[parent_y])
    {
        parent[parent_x] = parent_y;
    }
    else
    {
        parent[parent_y] = parent_x;
        rank[parent_x]++;
    }
}

int Solution::solve(vector<int> &a, vector<int> &b, vector<vector<int>> &c)
{

    // n is the size of permutation array
    int n = a.size();
    // for disjoint set
    vector<int> parent(n + 1), rank(n + 1);
    for (int i = 0; i <= n; i++)
    {
        rank[i] = 0;
        parent[i] = i;
    }

    // add relation in disjoint set
    for (int i = 0; i < c.size(); i++)
    {
        int x = a[c[i][0] - 1];
        int y = a[c[i][1] - 1];
        union_(x, y, parent, rank);
    }

    // check in same component or not
    for (int i = 0; i < n; i++)
    {
        if (find(a[i], parent) != find(b[i], parent))
            return 0;
    }

    return 1;
}

/*

  Time complexity  : O(n*log(n)+m*log(n)) = n*log(n)
  Space Complexity : O(n)

*/
