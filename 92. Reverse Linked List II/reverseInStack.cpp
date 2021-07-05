#include <iostream>
#include <vector>
#include <stack>
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
        if (!head || !head->next || left == right)
            return head;
        stack<ListNode *> s;
        ListNode *p = head;
        int i = 1;
        if (left == 1)
        {
            ListNode *l = head;
            int k = 1;
            while(k++<=right){
                s.push(l);
                l=l->next;
            }
            ListNode * rightNext = l;
            ListNode* newhead, *next, *prev == nullptr;
            while(!s.empty()){
                if(prev == nullptr){
                    prev = s.top();
                    newhead = prev;
                }
                else{
                    next = s.top();
                    prev->next=next;
                    prev = next;
                }
            }
            next->next = rightNext;
            return newhead;
        }

        while (i++ < left - 1)
            p = p->next;
        ListNode *leftPrev = p;
        while (i++ <= right)
        {
            p = p->next;
            s.push(p);
        }
        ListNode *rightNext = p->next;
        while (!s.empty())
        {
            leftPrev->next = s.top();
            s.pop();
            leftPrev = leftPrev->next;
        }
        leftPrev->next = rightNext;
        return head;
    }
};

int main()
{
}