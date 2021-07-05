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

/*          b
           / \ 
          a   c
        有三种情况
        第一种：abc组成的值最大
        第二种：a+b+b的父节点
        第三种：c+b+b的父节点 */

class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        int sum = INT_MIN;
        maxSum(root, sum);
        return sum;
    }

    int maxSum(TreeNode *root, int &sum)
    {
        if (root == nullptr)
            return 0;

        int leftSum = maxSum(root->left, sum);
        int rightSum = maxSum(root->right, sum);
        int left_mid_right = max(leftSum,0) + max(rightSum, 0) + root->val;
        int straight = max(0, max(leftSum, rightSum)) + root->val;
        sum = max(max(left_mid_right, straight), sum);
        return straight;
    }
};

int main()
{
}