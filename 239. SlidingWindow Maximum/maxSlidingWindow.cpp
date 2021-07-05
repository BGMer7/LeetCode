#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        multiset<int> win;
        for (int i = 0; i < k; i++)
        {
            win.insert(nums[i]);
        }
        vector<int> res;
        res.push_back(*win.rbegin());
        for (int i = 0; i < n - k; i++)
        {
            win.erase(win.find(nums[i]));
            win.insert(nums[i + k]);
            res.push_back(*win.rbegin());
        }
        return res;
    }
};

int main()
{
    vector<int> nums{3, 5, 1, 6, 3, 2, 8, 4, 2, 5, 2, 7, 3, 66, 2, 5};
    Solution sol;
    vector<int> res;
    res = sol.maxSlidingWindow(nums, 4);
    for (auto c : res)
    {
        cout << c << " ";
    }
}