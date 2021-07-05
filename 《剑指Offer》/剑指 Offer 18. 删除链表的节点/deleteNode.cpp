#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    // ListNode *deleteNode(ListNode *head, int val)
    // {
    //     while (head && head->val == val)
    //         head = head->next;

    //     ListNode *p = head;
    //     while (p->next)
    //     {
    //         if (p->next->val == val)
    //             p->next = p->next->next;
    //         else
    //             p = p->next;
    //     }
    //     return head;
    // }

    ListNode *deleteNode(ListNode *head, int val)
    {
        if (!head)
            return nullptr;

        head->next = deleteNode(head->next, val);
        if (head->val == val)
            return head->next;

        return head;
    }
};

int main() {}