#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        vector<int> m(128);
        int left = 0, right = 0, need = t.size(), minStart = 0, minLen = INT_MAX;
        for (char ch : t)
            ++m[ch]; //统计t中字符出现次数
        while (right < s.size())
        {
            /* code */
            if (m[s[right]] > 0) // 表示这个字符还需要
                --need;
            --m[s[right]]; // 这个字符的需求-1
            ++right;
            while (need == 0)
            {
                if (right - left < minLen)
                {
                    minStart = left;
                    minLen = right - left;
                }
                if (++m[s[left]] > 0)
                    ++need; //窗口左移
                ++left;
            }
        }
        if (minLen != INT_MAX)
            return s.substr(minStart, minLen);
        return "";
    }
};

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution sol;
    string res;
    res = sol.minWindow(s, t);
    cout << res;
}