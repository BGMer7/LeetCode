#include <iostream>
#include <vector>
#include <unordered_set>

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
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        unordered_set<int> to_del(to_delete.begin(), to_delete.end());
        vector<TreeNode *> res;
        root = helper(root, res, to_del);
        if (root)
            res.push_back(root);
        return res;
    }

    TreeNode *helper(TreeNode *root, vector<TreeNode *> &res, unordered_set<int> to_del)
    {
        if (root == nullptr)
            return root;
        root->left = helper(root->left, res, to_del);
        root->right = helper(root->right, res, to_del);
        if (to_del.count(root->val))
        {
            if (root->left)
                res.push_back(root->left);
            if (root->right)
                res.push_back(root->right);
            root = nullptr;
        }
        return root;
    }
};

int main()
{
}