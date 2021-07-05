#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class SolutionReverseList
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *s = head;
        ListNode *f = head;
        while (f != nullptr && f->next != nullptr)
        {
            f = f->next->next;
            s = s->next;
        }
        // 快慢指针找单链表中点的时候，如果链表的长度是奇数，那么slow就是正中间的节点
        // 如果链表的长度是偶数，那么slow就是偏右边的节点

        ListNode *tail = reverseList(s);
        while (tail)
        {
            if (head->val != tail->val)
            {
                return false;
            }
            else
            {
                head = head->next;
                tail = tail->next;
            }
        }
        return true;
    }

    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode *p = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};

class SolutionVector
{
public:
    vector<int> ListVal;

    bool isPalindrome(ListNode *head)
    {
        while (head->next != nullptr && head != nullptr)
        {
            ListVal.push_back(head->val);
            head = head->next;
        }

        int l = 0;
        int r = ListVal.size() - 1;
        while (l <= r)
        {
            if (ListVal[l] != ListVal[r])
            {
                return false;
            }
            else
            {
                ++l;
                --r;
            }
        }
        return true;
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
    SolutionReverseList solR;
    cout << solR.isPalindrome(contain[0]);

    return 0;
}