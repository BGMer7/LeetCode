#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        std::string res = strs.empty() ? "" : strs[0];
        if (strs.size() <= 1)//首先排除的是vector里只有一个或者没有元素的情况
            return res;

        for (auto str1 : strs)
        {
            string str0 = res;
            res = "";
            for (int i = 0; i < min(str1.size(), str0.size()); ++i)//垂直扫描法
            {
                if (str0[i] != str1[i])
                    break;
                res += str1[i];
            }
            
            if (res.empty())
                return res;
        }
        return res;
    }
};

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    string res;
    Solution sol;
    res = sol.longestCommonPrefix(strs);
    cout << res << endl;
}