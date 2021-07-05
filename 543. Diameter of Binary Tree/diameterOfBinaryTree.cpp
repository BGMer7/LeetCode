#include <iostream>

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
    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;
        maxDiameter(root, diameter);
        return diameter;
    }

    // int diameterOfBinaryTree(TreeNode *root)
    // {
    //     if (root == nullptr)
    //         return 0;
    //     else
    //     {
    //         int l = maxDepth(root->left);
    //         int r = maxDepth(root->right);
    //     }
    //     if (l == 0)
    //         return r;
    //     if (r == 0)
    //         return l;
    //     if (l && r)
    //         return l + r + 2;
    // }
    // 这道题的关键就在于，最长的路径不一定经过根节点，好比有左子树非常茂盛，但是右子树的深度就只有1，那么最长的路径就不会路过根节点。
    // 这才导致必须要创建一个全局变量一直更新，否则的话这种方法就是正确的，100/104通过测试案例，如果出现上述情况那么是无法通过的。

    int maxDiameter(TreeNode *root, int &diameter)
    {
        if (root == nullptr)
            return 0;

        int leftmeter = maxDiameter(root->left, diameter);
        int rightmeter = maxDiameter(root->right, diameter);
        diameter = max(leftmeter + rightmeter, diameter);

        return max(leftmeter, rightmeter) + 1;
    }

    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        else
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main()
{

}