#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        vector<int> v1(26), v2(26);
        for (char s1 : s)
            ++v1[s1 - 'a'];
        for (char s2 : t)
            ++v2[s2 - 'a'];
        char res;
        for (int i(0); i < 26; ++i)
        {
            if (v1[i] != v2[i])
            {
                res = 'a' + i;
                break;
            }
        }
        return res;
    }
};

class SolutionBit
{
public:
    char findTheDiff(string s, string t)
    {
        int res = 0;
        for(char c: s) 
            res^=c;
        for(char c: t) 
            res^=c;
        return (char) res;
    }
};

int main()
{
    string s1 = "sadfasdghqwrgsa";
    string s2 = "sadfasdgfhqwrgsa";
    Solution sol;
    cout << sol.findTheDifference(s1, s2);
    string res("");
    string strArr("sdfsdf");
    string::iterator it = find(res.begin(), res.end(), 's');
}