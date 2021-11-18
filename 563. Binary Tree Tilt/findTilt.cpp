#include <iostream>
#include <stdlib.h>

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
    int sumFilt = 0;
    int findTilt(TreeNode *root)
    {
        dfs(root);
        return sumFilt;
    }

private:
    int dfs(TreeNode *root)
    {
        if (!root)
            return;
        int leftSum = dfs(root->left);
        int rightSum = dfs(root->right);

        sumFilt += abs(leftSum - rightSum);
        return leftSum + rightSum + root->val;
    }
};

int main() {}