#include <iostream>
#include <stack>
#include <queue>
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
private:
    bool isSub(TreeNode *A, TreeNode *B)
    {
        if (!B)
            return true;
        if (!A || A->val != B->val)
            return false;

        return isSub(A->left, B->left) && isSub(A->right, B->right);
    }

public:
    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        if (A == nullptr || B == nullptr)
            return false;
        bool res = false;

        if (A->val == B->val)
            res = isSub(A, B);

        if (res)
            return true;

        return isSubStructure(A->left, B) || isSubStructure(A->right, B);

        return res;
    }
};

int main()
{
    int i = 1;
    while (i++ < 10)
    {
        if (i == 3)
            break;
    }
    cout << i;
}