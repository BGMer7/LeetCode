#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

static int num(10);

class Solution
{
private:
    vector<string> path;
    vector<vector<string>> res;
    bool isPalidrome(const string &s, int left, int right)
    {
        for (int i(left), j(right); i < j; ++i, --j)
        {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }

    void backtracking(const string &s, int startIndex) {
        if(startIndex >=s.size()) {
            res.push_back(path);
            return ; 
        }
        for(int i(startIndex); i<s.size(); ++i) {
            if(isPalidrome(s, startIndex, i)) {
                string str = s.substr(startIndex, i-startIndex+1);
                path.push_back(str);
            } else 
                continue;
            backtracking(s, i+1);
            path.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        backtracking(s, 0);
        return res;
    }
};

int main() {
    const string s("aab");
    Solution sol;
    num++;
    printf("%d", num);
    vector<vector<string>> res = sol.partition(s);

}