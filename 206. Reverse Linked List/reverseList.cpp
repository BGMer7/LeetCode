// https://blog.csdn.net/liujian20150808/article/details/50640979
// 如何创建一个单链表并赋值并输出

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

class SolutionIteration
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev, *curr;
        prev = nullptr;
        curr = head;
        while (curr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

class SolutionRecursion
{
public:
    ListNode *reverseList(ListNode *node)
    {
        if (node == nullptr || node->next == nullptr)
        {
            cout << node << endl;
            return node;
        }

        ListNode *p = reverseList(node->next);
        node->next->next = node;
        node->next = nullptr;
        return p;
    }
};

int main()
{
    vector<ListNode *> contain;
    for (int i = 1; i < 6; i++)
    {
        ListNode *p = new ListNode(i);
        // p->val = i;
        contain.push_back(p);
    }
    for (int i = 0; i < 4; i++)
    {
        contain[i]->next = contain[i + 1];
    }
    SolutionRecursion sol;
    sol.reverseList(contain[0]);
    for (auto p : contain)
    {
        cout << p << endl;
        cout << p->val <<endl;
        cout << p->next <<endl;
        cout << endl;
    }
}