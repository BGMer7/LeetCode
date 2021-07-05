#include <iostream>
#include <stack>
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
    TreeNode *pre = NULL;

public:
    bool isValidBST(TreeNode *root)
    {
        if (root == NULL)
            return true;
        if (!isValidBST(root->left))
            return false;
        if (pre != NULL && root->val <= pre->val)
            return false;
        pre = root; //记录中序遍历的上一个节点
        cout << "left:" << left << " root:" << root << " right:" << right << endl;
        if (!isValidBST(root->right))
            return false;
        return true;
    }
};

int main()
{
}