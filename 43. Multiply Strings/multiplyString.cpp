#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        int m = num1.size(), n = num2.size();
        string res(m + n, '0');
        for (int i(m - 1); i >= 0; --i)
        {
            for (int j(n - 1); j >= 0; --j)
            {
                int cur = (num1[i] - '0') * (num2[j] - '0') + (res[i + j + 1] - '0');
                res[i + j + 1] = cur % 10 + '0'; // 低位
                res[i + j] += cur / 10;          // 进位
            }
        }
        for (int i(0); i < res.size(); ++i)
        {
            if (res[i] != '0')
                return res.substr(i);
        }
        return res;
    }
};

int main()
{
    string num1("12"), num2("12");
    Solution sol;
    string res = sol.multiply(num1, num2);
    cout << res;
}