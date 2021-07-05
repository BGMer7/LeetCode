#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minArray(vector<int> &numbers)
    {
        int res = INT_MAX;
        for (int num : numbers)
            res = min(res, num);
        return res;
    }
};

class SolutionBinary
{
public:
    int minArray(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] < nums[right]) right = mid;
            else left = mid+1;
        }
        return nums[left];
    }
};

int main() {
    vector<int> nums{1,3,5};
    Solution sol;
    cout << sol.minArray(nums);
}