#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    void printVec(vector<int> &nums)
    {
        for (auto c : nums)
        {
            cout << c << " ";
        }
        cout << endl;
    }

    vector<int> diffWaysToCompute(string expression)
    {
        vector<int> res, left, right;
        for (int i = 0; i < expression.size(); i++)
        {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
            {
                left = diffWaysToCompute(string(expression, 0, i));
                right = diffWaysToCompute(string(expression, i + 1, expression.size() - i - 1));
                // string(str, a, b) => a是起始index，b是起始index往后b位，而不是结束index
                for (auto leftRes : left)
                {
                    for (auto rightRes : right)
                    {
                        if (expression[i] == '+')
                            res.push_back(leftRes + rightRes);
                        if (expression[i] == '-')
                            res.push_back(leftRes - rightRes);
                        if (expression[i] == '*')
                            res.push_back(leftRes * rightRes);
                    }
                }
            }
        }
        if (res.empty())
            res.push_back(stoi(expression));
        return res;
    }
};

int main()
{
    string s = "5+1-3";
    cout << string(s, 0, 0);
    Solution sol;
    vector<int> res;
    res = sol.diffWaysToCompute(s);
    sol.printVec(res);
}