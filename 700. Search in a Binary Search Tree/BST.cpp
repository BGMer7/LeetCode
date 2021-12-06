#include <iostream>
#include <stdio.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return nullptr;
        }
        
        if (val == root->val) {
            return root;
        }

        return searchBST(val < root->val ? root->left : root->right, val);
    }
};

int main() {
    float rootbeer[4] = {0.0, 1.0, 2.0, 3.0};
    float things[4][4];

    // things[4] = rootbeer;


    return 0;
}