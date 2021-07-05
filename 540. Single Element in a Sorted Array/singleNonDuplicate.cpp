#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (left <= right) // 在leetcode的判定中，不能取等
        {
            mid = (left + right) >> 1;
            cout << left << " " << mid << " " << right << endl;
            cout << nums[left] << " " << nums[mid] << " " << nums[right] << endl;
            cout << endl;
            if (nums[mid] == nums[mid + 1])
            {
                if ((mid - left) % 2)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid;
                }
            }
            else if (nums[mid] == nums[mid - 1])
            {
                if ((mid - left) % 2)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid;
                }
            }
            else if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            {
                return nums[mid];
            }
            cout << left << " " << mid << " " << right << endl;
            cout << nums[left] << " " << nums[mid] << " " << nums[right] << endl;
            cout << endl;
        }
        return nums[left];
    }
};

int main()
{
    vector<int> nums{2,3,3,4,4,5,5,6,6};
    Solution sol;
    cout << sol.singleNonDuplicate(nums);
}