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
public:
    /* int minDepth(TreeNode *root) // DFS
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        int depth = INT_MAX;
        if (root->left)
            depth = min(depth, minDepth(root->left));

        if (root->right)
            depth = min(depth, minDepth(root->right));

        return depth + 1;
    } */

    int minDepth(TreeNode *root) // DFS
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;

        queue<TreeNode *> q;
        int depth = 0;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i(0); i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left)
                    q.emplace(node->left);

                if (node->right)
                    q.emplace(node->right);

                if (!node->left && !node->right)
                    return depth + 1;
            }
            ++depth;
        }
        return depth;
    }
};

int main() {}