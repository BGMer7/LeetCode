#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>

using namespace std;

bool rule(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

class Solution
{
public:
    void printVec(vector<int> &nums)
    {
        for (auto c : nums)
            cout << c << " ";
        cout << endl;
    }

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int n = nums.size();
        int max = INT_MIN;
        int min = INT_MAX;
        for (auto c : nums)
        {
            if (c > max)
                max = c;
            if (c < min)
                min = c;
        }
        int bucketNum = (max - min) + 1;
        vector<int> buckets(bucketNum);
        for (int i = 0; i < n; i++)
            buckets[nums[i] - min]++;
            
        vector<pair<int, int>> freq2num;
        for (int i = 0; i < buckets.size(); i++)
        {
            freq2num.push_back(make_pair(i + min, buckets[i]));
            // 因为做的时候是每一位都减去了min，才符合nums[0]的原则，所以索引需要把min加回来
        }
        cout << freq2num[0].first << " " << freq2num[0].second << endl;
        sort(freq2num.begin(), freq2num.end(), rule);
        // cout << freq2num[3].first << " " << freq2num[3].second << endl;
        vector<int> res{};

        int i = 0;
        while (k > 0)
        {
            int num = freq2num[i].first;
            res.push_back(num);
            --k;
            ++i;
        }

        return res;
    }
};

int main()
{
    vector<int> nums{-1, -1};
    Solution sol;
    vector<int> res;
    res = sol.topKFrequent(nums, 1);
    sol.printVec(res);
}