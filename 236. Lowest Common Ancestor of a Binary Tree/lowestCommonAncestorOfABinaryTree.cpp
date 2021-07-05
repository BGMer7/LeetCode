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
    unordered_map<int, TreeNode *> father;
    unordered_map<int, bool> isVisited;
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        dfs(root);
        while (p)
        {
            isVisited[p->val] = true;
            p = father[p->val];
        }
        while (q)
        {
            if (isVisited[q->val])
                return q;
            q = father[q->val];
        }
        return nullptr;
    }

    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        if (!root->left)
        {
            father[root->left->val] = root;
            dfs(root->left);
        }
        if (!root->right)
        {
            father[root->right->val] = root;
            dfs(root->right);
        }
    }
};

int main(){
    
}