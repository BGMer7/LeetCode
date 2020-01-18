#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int res = INT_MIN, curSum = 0;
        for (int num : nums)
        {
            curSum = max(curSum + num, num);
            res = max(res, curSum);
        }
        return res;
    }

    int findMaxSubArrayPosition(vector<int> &nums)
    {
        
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {23, 4, -3, 75, 23, -87};
    cout << sol.maxSubArray(nums) << endl;
}