#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int binaryFindMin(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (left < right)
        {
            mid = (left + right) >> 1;
            cout << left << " " << mid << " " << right << endl;
            cout << nums[left] << " " << nums[mid] << " " << nums[right] << endl;
            cout << endl;
            if (nums[mid] < nums[right])
                right = mid;
            else if (nums[mid] > nums[right])
                left = mid + 1;
            else
                --right;
            cout << left << " " << mid << " " << right << endl;
            cout << nums[left] << " " << nums[mid] << " " << nums[right] << endl;
            cout << endl;
        }
        return nums[left];
    }
};

int main()
{
    vector<int> nums{3, 4, 5, 6, 1, 2, 2};
    // int cnt;
    // int i = 0;
    // while (i < nums.size())
    // {
    //     if (nums[i] == 1)
    //     {
    //         i++;
    //         cnt++;
    //         continue;
    //         cout << "stop" ;
    //     }
    // }
    // cout << cnt << endl;
    // cout << i << endl;
    Solution sol;
    int res = sol.binaryFindMin(nums);
    cout << res << endl;
}