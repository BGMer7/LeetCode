#include <vector>
#include <algorithm>

class Solution
{
public:
    int singleNumber(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        int i = nums.size();
        for (int i = 0; i + 3 < n; i += 3)
        {
            if (nums[i] != nums[i + 2])
                return nums[i] ^ nums[i + 1] ^ nums[i + 2];
        }
        return nums[n - 1];
    }
};