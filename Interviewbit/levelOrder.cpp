#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *node);
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> Solution::levelOrder(TreeNode *node)
{

    vector<vector<int>> ans;

    // if there is no any node
    if (node == NULL)
        return ans;

    queue<TreeNode *> q;
    q.push(node);

    while (!q.empty())
    {
        //find size of current level
        int sz = (int)q.size();

        vector<int> currLevelNode;

        // traverse current level and push it child
        while (sz--)
        {
            TreeNode *frontNode = q.front();
            q.pop();

            currLevelNode.push_back(frontNode->val);

            if (frontNode->left)
                q.push(frontNode->left);
            if (frontNode->right)
                q.push(frontNode->right);
        }

        //store current level
        ans.push_back(currLevelNode);
    }
    return ans;
}

/*

  Time complexity  : O(n)
  Space Complexity : O(n)

*/