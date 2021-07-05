#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        int n = T.size();
        vector<int> res(n);
        stack<int> s; // 这题思路的关键在于，单调栈中存放的是index而不是具体的数字
        
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && T[s.top()] < T[i])
            {
                res[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};

main()
{
    vector<int> temperatures{34, 43, 32, 45, 23, 45, 35, 32, 65, 33, 27, 59, 83, 48, 58, 79, 34, 74, 85, 32};
    Solution sol;
    vector<int> res;
    res = sol.dailyTemperatures(temperatures);
}