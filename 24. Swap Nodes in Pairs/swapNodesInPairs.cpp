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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *front = head;
        ListNode *rear = head->next;
        ListNode *tmp = rear->next;
        rear->next = front;
        front->next = swapPairs(tmp);
        return rear;
    }
    
};

void showList(ListNode *head)
{
    while (head)
    {
        cout << head->val << ", ";
        head = head->next;
    }
}

main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    Solution sol;
    ListNode *res;
    showList(head);
    res = sol.swapPairs(head);
    //cout << res->val << endl;
    showList(res);
}