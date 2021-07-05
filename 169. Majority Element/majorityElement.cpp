#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    /* int majorityElement(vector<int> &nums) // 排序
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - 1];
    } */

    /* int majorityElement(vector<int> &nums) // 随机找一个，看看是不是众数
    {
        int size = nums.size();
        if (size == 1)
            return nums[0];
        while (1)
        {
            int count = 0, num = rand() % (size - 1);
            int pivot = nums[num];
            for (int n : nums)
                if (n == pivot)
                    count++;

            if (count > (size / 2))
                return pivot;
        }
        return -1;
    } */

    int majorityElement(vector<int> nums)
    {
        int count = 1, majority = nums[0];
        for (int i(0); i < nums.size(); i++)
        {
            if (count == 0)
            {
                count++;
                majority = nums[i];
            }

            else if (nums[i] == majority)
                count++;
            else
                count--;
        }
        return majority;
    }
};

int main()
{
    vector<int> nums{1, 1, 1, 4, 4, 4, 4, 4, 4, 4, 3, 2, 2};
    Solution sol;
    cout << sol.majorityElement(nums);
}