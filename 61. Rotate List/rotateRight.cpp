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

class Solution2Ptrs
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || k == 0)
            return head;

        int length = 0;
        auto tmp = head;
        while (tmp != nullptr && ++length > 0)
            tmp = tmp->next;
        k %= length; // 如果没有将k整除的步骤，遍历链表将会超出空间
        if (k == 0)
            return head;

        ListNode *slow = head;
        ListNode *fast = head;
        for (int i = 0; i < k; i++)
        {
            fast = fast->next;
        }
        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *newHead = slow->next;
        slow->next = nullptr;
        fast->next = head;
        return newHead;
    }
};

class SolutionCycle
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || k == 0)
            return head;
        int length = 1;
        auto tmp = head;
        while (tmp->next != nullptr && ++length > 0)
        // 这里的判断条件和上面的实际上是一样的，因为已经判定过链表不为空，所以可以直接从1开始
        // 这样的好处在于不用遍历到最后一个空指针，这样遍历结束的时候，tmp就是尾指针，可以直接指向头指针
            tmp = tmp->next;
        k %= length;
        if (k == 0)
            return head;

        tmp->next = head;
        for(int i = 0;i<length -k;i++){
            head = head->next;
            tmp = tmp->next;
        }
        tmp->next = nullptr;
        return head;
        

        
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
    // for (auto p : contain)
    // {
    //     cout << p << endl;
    //     cout << p->val << endl;
    //     cout << p->next << endl;
    //     cout << endl;
    // }

    Solution2Ptrs sol;
    sol.rotateRight(contain[0], 2);
}