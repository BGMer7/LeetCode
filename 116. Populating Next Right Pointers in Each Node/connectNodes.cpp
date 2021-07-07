#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return root;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int level = q.size();

            for (int i(0); i < level; ++i)
            {
                Node *head = q.front();
                q.pop();
                if (i < level - 1)
                    head->next = q.front();

                if (head->left)
                    q.push(head->left);
                if (head->right)
                    q.push(head->right);
            }
        }
        return root;
    }
};

int main() {}