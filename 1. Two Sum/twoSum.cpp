#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> m;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i)
        {
            int n = nums[i];
            if (m.find(target - n) != m.end())
            {
                res.push_back(m[target - n]);
                res.push_back(i);
            }
            else
                m[n] = i;
        }
        return res;
    }
};

int main()
{
    vector<int> nums{2, 7, 8, 11};
    Solution sol;
    vector<int> res = sol.twoSum(nums, 9);
    cout << res[0]  << res[1]<< endl;
}