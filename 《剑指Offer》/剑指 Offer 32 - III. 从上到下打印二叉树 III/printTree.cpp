#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;

        queue<TreeNode *> q;
        q.push(root);
        bool isOdd = true;
        while (!q.empty())
        {
            int sz = q.size();
            vector<int> tmp(sz);
            for (int i(0); i < sz; ++i)
            {
                TreeNode *node = q.front();
                q.pop();

                if (node->left)
                    q.emplace(node->left);
                if (node->right)
                    q.emplace(node->right);

                if (isOdd)
                    tmp[i] = node->val;
                else
                    tmp[sz - i - 1] = node->val;
            }
            isOdd = !isOdd;
            res.push_back(tmp);
        }
        return res;
    }
};

int main() {}
