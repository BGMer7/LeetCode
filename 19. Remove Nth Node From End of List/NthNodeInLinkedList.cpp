#include <iostream>
#include <vector>
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(9), *fast = dummy, *low = dummy;
        dummy->next = head;
        while (n-- > 0)
            fast = fast->next;
        while (fast != NULL)
        {
            if (fast->next == NULL)
                low->next = low->next->next;
            else
                low = low->next;
            fast = fast->next;
        }
        return dummy->next;
    }
};

main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    ListNode *numsList = new ListNode(nums.back());
    nums.pop_back();
    numsList->next = new ListNode(nums.back());
    nums.pop_back();
    numsList->next = new ListNode(nums.back());
    nums.pop_back();
    numsList->next = new ListNode(nums.back());
    nums.pop_back();
    numsList->next = new ListNode(nums.back());
    nums.pop_back();
    numsList->next = new ListNode(nums.back());
    nums.pop_back();
    numsList->next = new ListNode(nums.back());

    Solution s;
    s.removeNthFromEnd(numsList, 2);
}