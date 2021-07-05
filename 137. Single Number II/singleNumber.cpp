#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int prev = 0, curr = 1, rear = 2;
        sort(nums.begin(), nums.end());
        if (nums[0] != nums[1])
            return nums[0];
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];
        while (rear < nums.size())
        {
            if (nums[curr] != nums[prev] && nums[curr] != nums[rear])
                return nums[curr];
            else
            {
                rear++;
                curr++;
                prev++;
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> nums{1, 1, 4, 4, 6, 7, 7, 7, 5, 5, 5, 3, 4};
    Solution sol;
    cout << sol.singleNumber(nums);
}