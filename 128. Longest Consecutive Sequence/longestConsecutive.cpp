#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <math.h>
#include <map>

using namespace std;

class Solution // 时间复杂度nlogn的写法
{
public:
    int longestConsecutive(vector<int> &nums) // sort, then find longest consecutive
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int count = 1;
        int res = count;
        int prev = nums[0];
        for (int i = 1; i < n; i++)
        {
            int cur = nums[i];
            if (cur - prev == 0)
                continue;
            if (cur - prev == 1)
                count++;
            else
            {
                res = max(count, res);
                count = 1;
            }
            prev = cur;
        }
        res = max(res, count);
        return res;
    }
};

class HashSolution
{
public:
    int longestConsecutive(vector<int> nums)
    {
        int n = nums.size();
        unordered_map<int, int> m;
        int min = INT_MAX;
        int max = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > max)
                max = nums[i];
            if (nums[i] < min)
                min = nums[i];
            m.insert({nums[i], i});
        }
        int count = 0;
        int res = 0;
        // if (m.find(m[2]) != m.end())
        // {
        //     cout << "zhaodaole1";
        // }
        // if (m[0])
        // {
        //     cout << "zhaodaole";
        // }
        // cout << "min:" << min << " max:" << max << endl;
        for (int i = min; i <= max; i++)
        {
            if (m.count(i))
            {
                count++;
            }
            else
            {
                count > res ? res = count : res = res;
                count = 0;
            }
            cout << "i:" << i << " count: " << count << endl;
        }
        count > res ? res = count : res = res;
        return res;
    }
};

int main()
{
    vector<int> nums{9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6};
    int res;
    // Solution Sol;
    // res = Sol.longestConsecutive(nums);
    // cout << res;
    HashSolution hsol;
    res = hsol.longestConsecutive(nums);
    cout << res;
}