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

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode *slow, *fast;
        slow = head;
        fast = head;
        while (fast != nullptr)
        {
            slow = slow->next;
            if (fast->next == nullptr)
                return nullptr;
            fast = fast->next->next;
            if (slow == fast)
            {
                ListNode *std;
                std = head;
                while (std != slow)
                {
                    std = std->next;
                    slow = slow->next;
                }
                return std;
            }
        }
        return nullptr;
    }
};

class SolutionSet
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        unordered_set<ListNode *> visited_nodes;
        while (head != nullptr)
        {
            if (visited_nodes.count(head))
            {
                return head; //直接就找到的是那个重复的node，然后讲函数返回
            }
            visited_nodes.insert(head);
            head = head->next;
        }
        return nullptr; //如果走到这一步，说明这是一个单链表，返回nullptr
    }
};

int main()
{
    return 0;
}
