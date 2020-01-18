#include <iostream>
#include <list>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        else if (!l2)
            return l1;
        else if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
std::ostream &operator<<(std::ostream &ostr, const std::list<int> &list)
{
    for (auto &i : list)
    {
        ostr << " " << i;
    }
    return ostr;
}// the offical usage to cout the list

int main(){
    list<int> list1{1,3,5,7};
    list<int> list2{2,4,6,8};
    list1.merge(list2); //the <list>lib usage, also offical usage
    cout << list1 << '\n'; //'\n' is faster than endl
    Solution s;
    //s.mergeTwoList(list1, list2);
    //wrong usage: no suitable conversion function from "std::list<int, std::allocator<int>>" to "ListNode *" exists
    

}