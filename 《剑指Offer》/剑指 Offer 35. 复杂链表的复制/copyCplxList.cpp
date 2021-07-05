#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return head;
        Node *cur = head;
        unordered_map<Node *, Node *> m;
        while (cur)
        {
            m[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;

        while (cur)
        {
            m[cur]->next = m[cur->next];
            m[cur]->random = m[cur->random];
            cur = cur->next;
        }

        return m[head];
    }
};

int main() {}