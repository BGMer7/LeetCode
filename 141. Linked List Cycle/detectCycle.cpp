#include <list>
#include <iostream>
#include <stdio.h>
#include <unordered_set>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution1
{
public:
    bool hasCycle(ListNode *head)
    {
        unordered_set<ListNode *> s;
        while (head != nullptr)
        {
            if (s.count(head))
                return false;
            else
                s.insert(head);
            head=head->next;
        }
        return true;
    }
};

class Solution2
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }
        return false;
    }
};

int main(){}
