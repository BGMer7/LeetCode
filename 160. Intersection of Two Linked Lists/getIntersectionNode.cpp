#include <vector>
#include <unordered_map>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class SolutionHashmap
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_map<ListNode *, int> map;
        while (headA)
        {
            ++map[headA];
            headA = headA->next;
        }

        while (headB)
        {
            if (map[headB])
                return headB;
            else
            {
                headB = headB->next;
            }
        }
        return NULL;
    }
};

class SolutionTwoPtrs
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *ptrA = headA;
        int LengthA = 0;
        ListNode *ptrB = headB;
        int LengthB = 0;
        while (ptrA)
        {
            ++LengthA;
            ptrA = ptrA->next;
        }
        while (ptrB)
        {
            ++LengthB;
            ptrB = ptrB->next;
        }
        
        ptrA = headA;
        ptrB = headB;
        if (LengthA >= LengthB)
        {
            int i = 0;
            while (i < (LengthA - LengthB))
            {
                ptrA = ptrA->next;
                ++i;
            }
            while (ptrA)
            {
                if (ptrA == ptrB)
                {
                    return ptrA;
                }
                else
                {
                    ptrA = ptrA->next;
                    ptrB = ptrB->next;
                }
            }
            return NULL;
        }

        if (LengthA < LengthB)
        {
            int i = 0;
            while (i < (LengthB - LengthA))
            {
                ptrB = ptrB->next;
                ++i;
            }
            while (ptrA)
            {
                if (ptrA == ptrB)
                {
                    return ptrA;
                }
                else
                {
                    ptrA = ptrA->next;
                    ptrB = ptrB->next;
                }
            }
            return NULL;
        }
    }
};

int main()
{
    return 0;
}