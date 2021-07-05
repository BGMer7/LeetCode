#include <iostream>
#include <vector>

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
    vector<int> temp;
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        dfs(root, sum);
        return res;
    }

    void dfs(TreeNode *root, int sum)
    {
        if (!root)
            return;
        temp.push_back(root->val);
        dfs(root->left, sum - root->val);
        dfs(root->right, sum - root->val);
        if (sum == root->val && !root->left && !root->right)
            res.push_back(temp);

        temp.pop_back();
    }
};

int main()
{
}