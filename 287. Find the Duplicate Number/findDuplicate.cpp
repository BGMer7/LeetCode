#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 2)
            return nums[0];
        vector<bool> isFound(n + 1, false);
        for (auto num : nums)
        {
            if (!isFound[num])
                isFound[num] = true;
            else
                return num;
        }
        return -1;
    }

    int findDuplicateSort(vector<int> &nums) // 先排序，再找重复的，其实可以再用二分查找优化
    {
        sort(nums.begin(), nums.end());
        int i = 0, j = 1;
        while (j < nums.size())
        {
            if (nums[i++] == nums[j++])
                return i;
        }
        return -1;
    }

    int findDuplicatePtrs(vector<int> &nums) // 快慢指针
    {
        // 这道题能用快慢指针的原理在于，一共n个元素，但是他有n+1个vector长度
        // 因此
        int fast = 0, slow = 0;
        while (true)
        {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if (fast == slow)
                break;
        }
        int finder = 0;
        while (true)
        {
            finder = nums[finder];
            slow = nums[slow];
            if (slow == finder)
                break;
        }
        return slow;
    }
};

int main()
{
    std::vector<int> nums{1, 4, 5, 3, 2, 2};
    Solution sol;
    std::cout << sol.findDuplicate(nums);
}