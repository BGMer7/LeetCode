#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        vector<int> temp;
        ListNode ptr * = lists[1];
    }

    vector<ListNode *> testLists;
    ListNode *List1 = new ListNode(0);
    ListNode *List2 = new ListNode(1);
    List1->next = new ListNode(2);
    List1->next = new ListNode(4);
    ListNode *List2 = new ListNode(1);
    List2->next = new ListNode(3);
    List2->next = new ListNode(5);
    ListNode *List3 = new ListNode(6);
    List3->next = new ListNode(7);
    List3->next = new ListNode(8);
    testLists.push_back(*List1);
    testLists.push_back(*List2);
    testLists.push_back(*List3);
};

main()
{
    vector<ListNode *> testLists;
    ListNode *List1 = new ListNode(0);
    List1->next = new ListNode(2);
    List1->next = new ListNode(4);
    ListNode *List2 = new ListNode(1);
    List2->next = new ListNode(3);
    List2->next = new ListNode(5);
    ListNode *List3 = new ListNode(6);
    List3->next = new ListNode(7);
    List3->next = new ListNode(8);
    testLists.push_back(*List1);
    testLists.push_back(*List2);
    testLists.push_back(*List3);
}