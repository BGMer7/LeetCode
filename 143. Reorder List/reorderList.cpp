#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        vector<ListNode *> nums;
        while (head)
        {
            nums.push_back(head);
            head = head->next;
        }
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            nums[left]->next = nums[right];
            ++left;
            if (left >= right)
                break;
            nums[right]->next = nums[left];
            --right;
        }
        nums[left]->next = nullptr;
    }
};

int main() {}