#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *res = nullptr;
        if (lists.size() == 0)
            return nullptr;
        else if (lists.size() < 2)
            return lists[0];
        else
        {
            ListNode *res;
            for (int i = 0; i < lists.size(); i++)
            {
                res = mergeLists(res, lists[i]);
            }
        }
        return res;
    }

    ListNode *mergeLists(ListNode *node1, ListNode *node2)
    {
        if (!node1)
            return node2;
        else if (!node2)
            return node1;
        else if (node1->val < node2->val)
        {
            node1->next = mergeLists(node1->next, node2);
            return node1;
        }
        else
        {
            node2->next = mergeLists(node1, node2->next);
            return node2;
        }
    }
};

class List2Vec
{
private:
    vector<int> resVec;

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        for (int i = 0; i < lists.size(); i++)
        {
            ListNode *head = lists[i];
            while (head)
            {
                resVec.push_back(head->val);
            }
        }
        sort(resVec.begin(), resVec.end());
        for (int i = 0; i < resVec.size() - 2; i++)
        {

            resVec[i]->next = resVec[i + 1];
        }

        vector<ListNode *> contain;
        for (int i = 0; i < resVec.size(); i++)
        {
            ListNode *p = new ListNode(resVec[i]);
            // p->val = i;
            contain.push_back(p);
        }
        for (int i = 0; i < resVec.size(); i++)
        {
            contain[i]->next = contain[i + 1];
        }
        ListNode *head = contain[0];
        return head;
    }
};

int main()
{
    return 0;
}