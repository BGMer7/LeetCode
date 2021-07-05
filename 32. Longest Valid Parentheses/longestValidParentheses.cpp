#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int res = 0, left = 0, right = 0; // left左括号数量，right右括号数量
        for (int i(0); i < s.size(); i++)
        {
            if (s[i] == '(')
                left++;
            else
                right++;
            if (left == right)
                res = max(res, left + right);
            else if (right > left)
                left = right = 0;
        }
        left = right = 0;
        for (int i(s.size() - 1); i >= 0; i--)
        {
            if (s[i] == '(')
                left++;
            else
                right++;
            if (left == right)
                res = max(res, left + right);
            else if (right < left)
                left = right = 0;
        }
        return res;
    }
};

int main(){
    string s("()()()(()())()))()()()(()(())(");
    Solution sol;
    cout << sol.longestValidParentheses(s);
}
