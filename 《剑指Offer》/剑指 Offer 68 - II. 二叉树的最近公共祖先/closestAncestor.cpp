#include <iostream>
#include <unordered_map>
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
    unordered_map<int, TreeNode *> father;
    unordered_map<int, bool> isVisited;

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        unordered_map<int, TreeNode *> father;
        unordered_map<int, bool> isVisited;
        father[root->val] = nullptr;
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
            else
                q = father[q->val];
        }
        return nullptr;
    }

    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        if (root->left)
        {
            father[root->left->val] = root;
            dfs(root->left);
        }

        if (root->right)
        {
            father[root->right->val] = root;
            dfs(root->right);
        }
    }
};

class SolutionBool
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root || root == p || root == q)
            return root;
        TreeNode *l = lowestCommonAncestor(root->left, p, q),
                 *r = lowestCommonAncestor(root->right, p, q);

        if (l && r)
            return root;
        else if (l)
            return l;
        else if (r)
            return r;
        else
            return nullptr;
    }
};

int main() {

}