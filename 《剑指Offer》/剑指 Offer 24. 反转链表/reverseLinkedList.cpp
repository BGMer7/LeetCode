#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    // ListNode *reverseList(ListNode *head)
    // {
    //     if(!head || !head->next)
    //         return head;

    //     ListNode *p = reverseList(head->next);
    //     head->next->next = head;
    //     head->next = nullptr;
    //     return p;
    // }

    ListNode *reverseList(ListNode *head)
    {
        if (!head)
            return head;
        
        ListNode *prev = nullptr, *next;
        while(head) {
            next = head->next;
            head ->next = prev;
            prev = head;
            head = next;
        }
        return prev; // 此时的next是nullptr
    }
};

int main() {}