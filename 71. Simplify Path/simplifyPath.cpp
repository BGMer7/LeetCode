#include <string>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        string res("");
        path = path+'/';
        int n = path.size();
        string dir("");
        for (int i(0); i < n; ++i)
        {
            if (path[i] != '/')
                dir = dir + path[i];
            else
            {
                if (dir == ".." && !res.empty())
                {
                    while (res.back() != '/')
                        res.pop_back();
                    res.pop_back();
                }
                else if (dir != ".." && dir != "." && !dir.empty())
                    res = res + "/" + dir;
                dir.clear();
            }
            // cout << res << endl;
        }
        return res.empty() ? "/" : res;
    }
};

int main()
{
    // string s("..///");
    // int index = s.find('/');
    // cout << s.substr(index);
    Solution sol;
    cout << sol.simplifyPath("/a//b////c/d//././/..");
}
