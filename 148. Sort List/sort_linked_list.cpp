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
            // cout << "before: ";
            // cout << "num:" << num << " ";
            // cout << "curSum:" << curSum << " ";
            // cout << "res:" << res << "\n";
            curSum = max(curSum + num, num);
            res = max(res, curSum);
            // cout << "after: ";
            // cout << "num:"<< num << " ";
            // cout << "curSum:" << curSum << " ";
            // cout << "res:" << res << "\n";
        }
        return res;
    }
};

int main()
{
    vector<int> nums{3, -6, 35, 64, -65, 72, -6, 56, 367, -213, 323, 5};
    Solution s;
    int res;
    res = s.maxSubArray(nums);
    cout << res;
}