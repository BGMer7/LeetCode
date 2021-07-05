#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    // TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) // recursion
    // {
    //     if (q->val < root->val && p->val < root->val)
    //         return lowestCommonAncestor(root->left, p, q);
    //     else if (q->val > root->val && p->val > root->val)
    //         return lowestCommonAncestor(root->right, p, q);
    //     else
    //         return root;
    //     return nullptr;
    // }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) // iteration
    {
        while (1)
        {
            if (q->val < root->val && p->val < root->val)
                root = root->left;
            else if (q->val > root->val && p->val > root->val)
                root = root->right;
            else
                break;
        }
        return root;
    }
};

int main()
{
}