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

class SolutionUp // 自顶向下递归
{
public:
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        int left = depth(root->left);
        int right = depth(root->right);
        return (abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right));
    }

    int depth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        else
            return max(depth(root->left), depth(root->right)) + 1;
    }
};

class SolutionDown // 自底向上递归
{
public:
    bool isBalanced(TreeNode *root)
    {
        return depth(root)>=0;
    }

    int depth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        if (abs(left - right) > 1 || left == -1 || right == -1)
            return -1;
        else
            return max(left, right) + 1;
    }
}