#include <iostream>
#include <vector>

using namespace std;

/**
 * module_name:
 * module_description:
 * author: BGM
 * create_time: 2023/07/12 16:42:07
 */
class Solution
{
public:
    int removeElementTwoPtr(vector<int> &nums, int val)
    {
        int n = nums.size();
        int left = 0;
        for (int right = 0; right < n; right++)
        {
            if (nums[right] != val)
            {
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }

    int removeElement(vector<int> &nums, int val)
    {
        int left = 0, right = nums.size();
        while (left < right)
        {
            if (nums[left] == val)
            {
                nums[left] = nums[right - 1];
                right--;
            }
            else
            {
                left++;
            }
        }
        return left;
    }
};

int main()
{
    vector<int> nums = {3, 2, 3, 4, 2, 3, 2, 1, 5, 3};
    Solution sol;
    cout << sol.removeElement(nums, 2) << endl;
    cout << nums.size() << endl;
}