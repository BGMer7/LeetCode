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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
private:
    ListNode *getMid(ListNode *left, ListNode *right)
    {
        ListNode *slow = left, *fast = left;
        while (fast != right && fast->next != right)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    TreeNode *build(ListNode *left, ListNode *right)
    {
        if (left == right)
            return nullptr;

        ListNode *mid = getMid(left, right);
        TreeNode *p = new TreeNode(mid->val);
        p->left = build(left, mid);
        p->right = build(mid, nullptr);
        return p;
    }

public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        TreeNode *root = build(head, nullptr);
        return root;
    }
};

int main()
{
}