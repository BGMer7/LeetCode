#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs){
        if (strs.size() == 0)
            return "";
        if (strs.size() == 1)
        {
            return strs[0];
        }

        string tmp = commonPrefixInTwoStrings(strs[0], strs[1]);
        for (int i = 2; i < strs.size(); i++) //从第二个开始，循环的去调用就好了
        {
            tmp = commonPrefixInTwoStrings(tmp, strs[i]);
        }
        return tmp;
    }

private:
    string commonPrefixInTwoStrings(string s1, string s2)
    {
        string res("");
        int t = min(s1.size(), s2.size());
        for (int i = 0; i < t; i++)
        {
            if (s1[i] != s2[i])
                break;
            res += s1[i];
        }
        return res;
    }

    string commonPrefixInTwoStringsWithSubstr(string s1, string s2)
    {
        int index = 0;
        int m = min(s1.size(), s2.size());
        for (int i = 0; i < m; i++)
        {
            if (s1[i] != s2[i])
                index = i;
        }
        return s1.substr(0, index);
    }
};

int main()
{
    Solution sol;
    vector<string> strs = {"hekkk", "hellkk", "hesss"};
    cout << sol.longestCommonPrefix(strs);
}