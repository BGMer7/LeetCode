#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

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


class Solution
{
private:
    unordered_map<Node*, Node*> cache;

public:
    Node *copyRandomList(Node *head)
    {
        if(!head)
            return nullptr;

        if(!cache[head]) {
            Node* new_head = new Node(head->val);
            cache[head] = new_head;
            new_head->next = copyRandomList(head->next);
            new_head->random = copyRandomList(head->random);
        }

        return cache[head];
    }
};