#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int> nums, int target)
{
    int left = 0, right = nums.size();
    // cout << left << right<<endl;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            right = mid;
        else if (nums[mid] < target)
            left = mid + 1;
        cout << left << " " << mid << " " << right << endl;
    }
    return left;
}

int main()
{
    vector<int> nums{1,3,5,6,7,8,9,10};
    int res = searchInsert(nums, 2);
    cout << res;
}