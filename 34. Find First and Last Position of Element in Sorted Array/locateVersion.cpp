#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // vector<int> searchRange(vector<int> &nums, int target)
    // {
    //     return 0;
    // }

    int binarySearch(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return right;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
        }

        return -1;
    }

    // 主函数
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.empty())
            return vector<int>{-1, -1};
        int lower = lower_bound(nums, target);
        int upper = upper_bound(nums, target) - 1; // 这里需要减1位
        if (lower == nums.size() || nums[lower] != target)
        {
            return vector<int>{-1, -1};
        }
        return vector<int>{lower, upper};
    }
    // 辅函数
    int lower_bound(vector<int> &nums, int target)
    {
        cout << "lower boundry:" << endl;
        int l = 0, r = nums.size(), mid;
        while (l < r)
        {
            mid = (l + r) / 2;
            if (nums[mid] >= target)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
            cout << "i: " << l << " j:" << r << " mid: " << mid <<endl;;
        }
        return l;
    }
    // 辅函数
    int upper_bound(vector<int> &nums, int target)
    {
        cout << "upper boundry" << endl;
        int l = 0, r = nums.size(), mid;
        while (l < r)
        {
            mid = (l + r) / 2;
            if (nums[mid] > target)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
            cout << "i: " << l << " j:" << r << " mid: " << mid <<endl;
        }
        return l;
    }
};

int main()
{
    vector<int> nums{5, 6 ,8,8,9,10};
    Solution sol;
    cout << sol.binarySearch(nums, 8) << endl;
    cout << endl;
    cout << sol.lower_bound(nums, 8) << endl;
    cout << endl;
    cout << sol.upper_bound(nums, 8) << endl;
}