

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
    bool isSymm(TreeNode *left, TreeNode *right)
    {
        if (!left && !right)
            return true;

        if (!left || !right)
            return false;

        if (left->val != right->val)
            return false;

        return isSymm(left->left, right->right) && isSymm(left->right, right->left);
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        if (!root->left && !root->right)
            return true;

        if (!root->left || !root->right)
            return false;

        if (root->left->val != root->right->val)
            return false;

        return isSymm(root->left, root->right);
    }
};