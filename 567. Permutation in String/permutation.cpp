#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution // 与Leetcode438几乎一致
{
public:
    // bool checkInclusion(string p, string s)
    // {
    //     vector<int> need(128), window(128);
    //     bool res = false;
    //     if (p.size() > s.size() || s.size() == 0)
    //         return res;
    //     for (char ch : p)
    //         need[ch]++;

    //     int left = 0, right = left + p.size() - 1;
    //     string sub = s.substr(0, p.size());
    //     for (auto ch : sub)
    //         window[ch]++;
    //     while (right < s.size())
    //     {
    //         if (window == need)
    //             return true;
    //         window[s[++right]]++;
    //         window[s[left++]]--;
    //     }
    //     return res;
    // }

    class Solution
    {
    public:
        bool checkInclusion(string s1, string s2)
        {
            int n = s1.size(), m = s2.size();
            if (n > m)
                return false;

            vector<int> need(26), window(26);
            for (char ch : s1)
                ++need[ch - 'a'];

            for (int i(0); i < n; ++i)
                ++window[s2[i] - 'a'];
            if (window == need)
                return true;
            for (int i(n); i < m; ++i)
            {
                ++window[s2[i] - 'a'];
                --window[s2[i - n] - 'a'];
                if (window == need)
                    return true;
            }
            return false;
        }
    };
};