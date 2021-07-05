#include <vector>
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
    vector<int> tmp;
    vector<vector<int>> res;

    void dfs(TreeNode *root, int target)
    {
        if (!root->left && !root->right && target == 0)
            res.push_back(tmp);
        tmp.push_back(root->val);
        if (root->left)
            dfs(root->left, target - (root->val));
        if (root->right)
            dfs(root->right, target - (root->val));
        tmp.pop();
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int target)
    {
        dfs(root, target);
        return res;
    }
};