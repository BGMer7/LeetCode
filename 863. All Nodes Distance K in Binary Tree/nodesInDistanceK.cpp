#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
    unordered_map<TreeNode *, TreeNode*> parents;
    vector<int> res;

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        findParents(root);
        dfs(target, nullptr, k);
        return res;
    }

    void findParents(TreeNode *root)
    {
        if (!root)
            return;
        if (root->left)
        {
            parents[root->left] = root;
            findParents(root->left);
        }
        if (root->right)
        {
            parents[root->right] = root;
            findParents(root->right);
        }
    }

    void dfs(TreeNode *target, TreeNode *pre, int k)
    { //
        if (!target)
            return;

        if (k == 0)
        {
            res.push_back(target->val);
            return;
        }

        if (target->left != pre)
            dfs(target->left, target, k - 1);

        if (target->right != pre)
            dfs(target->right, target, k - 1);

        if (parents[target] != pre)
            dfs(parents[target], target, k - 1);
    }
};