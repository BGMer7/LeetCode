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

/* class Solution // ListNode -> Vector -> ListNode 超时
{
public:
    ListNode *sortList(ListNode *head)
    {
        vector<int> v;
        ListNode *node = head;
        while (node)
        {
            v.push_back(node->val);
            node = node->next;
        }
        quickSort(v, 0, v.size() - 1);
        node = head;
        for (auto i : v)
        {
            node->val = i;
            node = node->next;
        }
        return head;
    }

private:
    void quickSort(vector<int> &v, int left, int right)
    {
        if (left >= right)
            return;
        int pivot = patition(v, left, right);
        quickSort(v, left, pivot - 1);
        quickSort(v, pivot + 1, right);
    }

    int patition(vector<int> &v, int left, int right)
    {
        for (int i(left); i < right; i++)
            if (v[i] < v[right])
                swap(v[left++], v[i]);
        swap(v[left], v[right]);
        return left;
    }
}; */

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *mid = middleNode(head);
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        return mergeTwoLists(left, right);
    }

private:
    ListNode *getMid(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        ListNode *prev = slow;
        while (fast && fast->next)
        {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        prev->next = nullptr; // 需要切开
        return slow;
    }

    ListNode *merge(ListNode *node1, ListNode *node2)
    {
        if (!node1)
            return node2;
        if (!node2)
            return node1;
        ListNode *head = new ListNode(0); // new一个节点，这个节点用来返回，再复制一个用来操作
        ListNode *node = head;
        while (node1 && node2)
        {
            if (node1->val <= node2->val)
            {
                node->next = node1;
                node1 = node1->next;
            }
            else
            {
                node->next = node2;
                node2 = node2->next;
            }
            node = node->next;
        }
        if (node1)
            node->next = node1;
        else
            node->next = node2;

        return head->next; // 用于返回的节点
    }
};