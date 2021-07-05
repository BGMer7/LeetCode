#include <vector>
#include <iostream>

using namespace std;

void printVector(vector<int> nums)
{
    for (auto n : nums)
    {
        cout << n << " ";
    }
    cout << endl;
}

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        for (int i = (n / 2) - 1; i >= 0; --i)
        {
            heapAdjust(nums, i, n - 1);
        }
        cout << nums[0] << endl;
        int largest;
        vector<int> largestNums;
        for (int t = n - 1; t > n - k - 1; --t)
        {
            largest = nums[0];
            largestNums.push_back(largest);
            swap(nums[0], nums[t]);
            heapAdjust(nums, 0, t - 1);
        }
        cout << "K largest nums are: " << endl;
        for (auto n : largestNums)
        {
            cout << n << " ";
        }
        cout << endl;
        return largest;
    }

    void heapAdjust(vector<int> &nums, int left, int right)
    {
        int dad = left;
        int son = dad * 2 + 1;

        while (son <= right)
        {
            if (son + 1 <= right && nums[son] < nums[son + 1])
                ++son;
            if (nums[dad] > nums[son])
                return;
            else
            {
                swap(nums[dad], nums[son]);
                dad = son;
                son = 2 * dad + 1;
            }

            printVector(nums);
        }
    }
};

void heapAdjust(vector<int> &nums, int left, int right)
{
    int dad = left, son = dad * 2 + 1;
    while (son <= right)
    {
        if (son + 1 <= right)
            nums[son] < nums[son + 1] ? son += 1 : son = son;
        if (nums[dad] > nums[son])
            return;
        else
        {
            swap(nums[son], nums[dad]);
            dad = son;
            son = 2 * dad + 1;
        }
    }
}

int main()
{
    vector<int> nums{5, 5, 5, 5, 5, 5, 5, 5, 6};
    Solution sol;
    int res = sol.findKthLargest(nums, 2);
    cout << res;
}
