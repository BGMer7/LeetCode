#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
    bool findStl(vector<int> &nums, int target)
    {
        vector<int>::iterator it = find(nums.begin(), nums.end(), target);
        return (it != nums.end());
    }

    bool search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (left <= right)
        {
            mid = (left + right) >> 1;
            cout << left << " " << mid << " " << right << endl;
            cout << nums[left] << " " << nums[mid] << " " << nums[right] << endl;
            cout << endl;

            if (nums[mid] == target)
                return true;
            if (nums[left] == nums[mid])
            {
                ++left;
                continue; // 一定要加continue，否则会数组越界
            }

            if (nums[left] < nums[mid])
            {
                if (nums[left] <= target && target < nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if (nums[mid] < target && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            cout << left << " " << mid << " " << right << endl;
            cout << nums[left] << " " << nums[mid] << " " << nums[right] << endl;
            cout << endl;
        }
        return false;
    }

    bool
    binarySearch(vector<int> nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            if (nums[middle] == target)
                return true;
            else if (nums[middle] < target)
                left = middle + 1;
            else if (nums[middle] > target)
                right = middle - 1;
        }
        return false;
    }
};

int main()
{
    vector<int> nums{1};
    Solution sol;
    cout << sol.search(nums, 0) << endl;
    // int a = 1;
    // int b = 2;
    // int c = (a + b) >> 1;
    // cout << c << endl;
}