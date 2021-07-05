#include <iostream>
#include <vector>
using namespace std;

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
public:
    ListNode *rightNext;
    ListNode *reverse(ListNode *head, int curNode, int right)
    {
        if (curNode == right)
        {
            rightNext = head->next;
            return head;
        }
        ListNode *p = reverse(head->next, curNode + 1, right);
        head->next->next = head;
        head->next = rightNext;
        return p;
    }

    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (head == nullptr || head->next == nullptr || left == right)
        {
            return head;
        }
        if (left == 1)
            return reverse(head, 1, right);
        int i = 1;
        ListNode *p = head;
        while (i++ < left - 1) // find the left node
            p = p->next;
        p->next = reverse(p->next, left, right);
        return head;
    }
};

int main()
{
    
}