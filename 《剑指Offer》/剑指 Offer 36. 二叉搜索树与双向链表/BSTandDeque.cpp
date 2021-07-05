#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val)
    {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution
{
public:
    Node *treeToDoublyList(Node *root)
    {
        if (root == nullptr)
            return nullptr;
        dfs(root);
        head->left = pre; // 头指针的前驱是尾指针，尾指针的后继是头指针
        pre->right = head;
        return head;
    }

private:
    Node *pre, *head;
    void dfs(Node *cur)
    {
        if (cur == nullptr)
            return;
        dfs(cur->left);
        if (pre != nullptr) // 只有遍历到第一个节点的时候，pre还是nullptr，后面的时候pre都已经赋值
        {
            cur->left = pre; // 建立双线连接
            pre->right = cur; 
        }
        else
            head = cur;
        pre = cur; // 往后移动一位
        dfs(cur->right);
    }
};

int main() {}