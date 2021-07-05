#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0;
        if (n == 2)
            return nums[0] > nums[1] ? 0 : 1;
        int left = 0, right = n - 1, mid = left + (left - right) / 2;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1])
                left = mid + 1;
            else if (nums[mid] > nums[mid + 1])
                right = mid;
        }
        cout << "peak number is " << nums[right] << endl;
        cout << "the index is " << right << endl;
        return right;
    }
};

main()
{
    vector<int> nums{1, 2, 3, 4, 5, 6, 7, 5, 1};
    Solution sol;
    cout << sol.findPeakElement(nums);
}