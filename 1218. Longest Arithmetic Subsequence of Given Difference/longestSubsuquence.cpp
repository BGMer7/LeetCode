#include <vector>
#include <unordered_map>
// #include <math.h>
// #include <algorithm>

class Solution
{
public:
    // 这个解法只适用子串，而不是子序列
    int longestSubarr(std::vector<int> &arr, int difference)
    {
        std::vector<int> diff;
        for (int i = 0; i < arr.size() - 1; ++i)
            diff.push_back(arr[i + 1] - arr[i]);
        int l = 0;
        int longest = 0;
        for (int i = 0; i < diff.size(); ++i)
        {
            if (diff[i] == difference)
                ++l;
            else
            {
                longest = std::max(l, longest);
                l = 0;
            }
        }
        longest = std::max(l, longest);
        return longest + 1;
    }

    int longestSubsequence(std::vector<int> &arr, int difference)
    {
        int longest = 0;
        std::unordered_map<int, int> dp;
        for (int i : arr)
        {
            dp[i] = dp[i - difference] + 1;
            longest = std::max(longest, dp[i]);
        }
        return longest;
    }
};