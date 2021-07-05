#include <iostream>
#include <string>
#include <deque>
#include <vector>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        deque<char> dq;
        int n = num.size();
        if (k >= n)
            return "0";
        for (int i(0); i < n; ++i)
        {
            while (!dq.empty() && dq.back() > num[i] && k)
            {
                dq.pop_back();
                --k;
            }
            dq.push_back(num[i]);
        }

        // 如果此时k还没用完，那么后面的数字都要被pop
        while (k-- > 0)
            dq.pop_back();
        // cout << dq.size() << endl;
        string res("");
        bool isLeadingZero = true;
        while (!dq.empty())
        {
            while (isLeadingZero && !dq.empty() && dq.front() == '0')
                dq.pop_front();
            isLeadingZero = false;
            if (!dq.empty())
            {
                char dig = dq.front();
                cout << dig;
                dq.pop_front();
                res = res + dig;
            }
        }
        return res.empty() ? "0" : res;
    }
};

class SolutionVector
{
public:
    string removeKdigits(string num, int k)
    {
        vector<char> stk;
        for (char c : num)
        {
            while (!stk.empty() && stk.back() > c && k)
            {
                --k;
                stk.pop_back();
            }
            stk.push_back(c);
        }
        while (k-- > 0)
            stk.pop_back();

        int start;
        string res("");
        for (int i(0); i < stk.size(); ++i)
        {
            if (stk[i] == '0')
                continue;
            start = i;
        }
        for (int i(start); i < stk.size(); ++i)
        {
            res = res + stk[i];
        }
        return res.empty() ? "0" : res;
    }
};