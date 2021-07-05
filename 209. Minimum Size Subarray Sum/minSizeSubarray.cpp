#include <vector>
#include<iostream>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int left = 0, right = 0, len = INT_MAX;
        int sum = 0;
        while (right < nums.size())
        {
            sum += nums[right];
            while (sum >= target)
            {
                len = min(len, right - left + 1);
                sum -= nums[left];
                left++;
            }
            ++right;
        }
        return len;
    }
};

int main()
{
    vector<int> nums{1,2,3,4,5};
    Solution sol;
    cout << sol.minSubArrayLen(15, nums);
}