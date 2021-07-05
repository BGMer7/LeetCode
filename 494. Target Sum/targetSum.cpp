#include <vector>
#include <iostream>

using namespace std;

class solution // 递归解法，time beats 12% memory beats 97%
{

public:
    int count = 0;
    int n = 0;
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;
        n = nums.size();
        calculate(nums, 0, sum, target);
        return count;
    }

    int calculate(vector<int> &nums, int index, int sum, int target)
    {
        if (index == n - 1)
        {
            if (sum == target)
                ++count;
        }
        else
        {
            calculate(nums, index + 1, sum += nums[index], target);
            calculate(nums, index + 1, sum -= nums[index], target);
        }
    }
};

class SolutionDP
{
    public:
    
}