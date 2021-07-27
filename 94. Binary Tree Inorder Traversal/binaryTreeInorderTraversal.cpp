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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        helper(root, res);
        return res;
    }

    void helper(TreeNode *root, vector<int> &res)
    {
        if (!root)
            return;

        helper(root->left, res);
        res.push_back(root->val);
        helper(root->right, res);
    }
};

class SolutionRecur
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        stack<TreeNode *> s;
        vector<int> res;
        while (root || !s.empty())
        {
            while (root)
            {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            res.push_back(root->val);
            s.pop();
            root = root->right;
        }
        return res;
    }
};

int main() {}