#include <vector>
#include <numeric>
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
    vector<int> res;

public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        dfs(root, false);
        return accumulate(res.begin(), res.end());
    }

    void dfs(TreeNode *root, bool isLeft)
    {
        if (!root->left && !root->right && isLeft)
            res.push_back(root->val);
        if (root->left)
            dfs(root->left, true);
        if (root->right)
            dfs(root->right, false);
    }
};