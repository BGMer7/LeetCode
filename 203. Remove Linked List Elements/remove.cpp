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
    ListNode *removeElements(ListNode *head, int val)
    {
        while (head && head->val == val)
            head = head->next;
        if (!head)
            return nullptr;
        if (!head->next)
            return head->val == val ? nullptr : head;

        ListNode *prev = head, *curr = head->next;
        while (curr != nullptr)
        {
            if (curr->val != val)
            {
                prev = curr;
                curr = curr->next;
            }
            else
            {
                prev->next = curr->next;
                curr = curr->next;
            }
        }

        return head;
    }

    ListNode *removeElementsRecursion(ListNode *head, int val)
    {
        if (!head)
            return nullptr;

        head->next = removeElementsRecursion(head->next, val);
        if (head->val == val)
            return head->next;

        return head;
    }
};