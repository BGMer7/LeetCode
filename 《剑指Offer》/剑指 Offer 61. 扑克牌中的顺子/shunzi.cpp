#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
public:
    bool isStraight(vector<int> &nums)
    {
        int maxBound = INT_MIN, minBound = INT_MAX;
        sort(nums.begin(), nums.end());
        int kings = 0;
        map<int, bool> isDuplicate;
        for (auto num : nums)
        {
            if (num == 0)
            {
                ++kings;
                continue;
            }
            if (isDuplicate.find(num) != isDuplicate.end())
                return false;
            isDuplicate[num] = true;
            maxBound = max(num, maxBound);
            minBound = min(num, minBound);
        }

        if (maxBound - minBound > 5)
            return false;
        else if (maxBound - minBound == 5)
            return true;

        return false;
    }
};