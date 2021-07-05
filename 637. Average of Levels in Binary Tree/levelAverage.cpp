#include <iostream>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    vector<double> res;
    void bfs(TreeNode *root)
    {
        if (!root)
            return;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            double sum = 0.0000;
            for (int i(0); i < n; ++i)
            {
                TreeNode *node = q.front();
                sum += node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                q.pop();
            }
            res.push_back(sum / n);
        }
    }

public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        bfs(root);
        return res;
    }
};