#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res; //用于存放所有的结果的vector
        string s(""); //用于存放每一个结果的string
        traceback(0, 0, n, s, res);
        return res;
    }

    void traceback(int left, int right, int n, string &s, vector<string> &res)
    {
        if (left == n && right == n) //说明所有的括号都已经放进来了
        {
            cout << s << endl;
            res.push_back(s);
            return;
        }
        if (left < n) //左边的括号还没有放完
        {
            s += "(";
            traceback(left + 1, right, n, s, res);
            s.pop_back(); //先把右括号都踢掉
            //可是怎么不重复呢？有一说一，没有看懂。
        }
        if (right < left) //还有没配对上的左括号
        {
            s += ")";
            traceback(left, right + 1, n, s, res);
            s.pop_back(); //踢掉右括号，同上，没懂。
        }
    }
};

main()
{
    int n = 10;
    Solution s;
    vector<string> res = s.generateParenthesis(n);
    cout << res.size() << endl;
}