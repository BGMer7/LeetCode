#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        int n = s.size(), dgt = 0;
        char preSign = '+'; //第一个数是正的
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            cout << "begin, i: " << i << endl;
            if (s[i] == ' ')
                continue;
            if (!isdigit(s[i]))
                preSign = s[i];
            else
            {
                while (isdigit(s[i]))
                    dgt = dgt * 10 + int(s[i] - '0'), i++;
                if (preSign == '+')
                    v.push_back(dgt);
                if (preSign == '-')
                    v.push_back(-dgt);
                if (preSign == '*')
                    v.back() *= dgt;
                    // 直接对于vector中的最后一个数字先做运算，将乘法结果代替原有的数字，这样子最后只需要做加法运算即可
                if (preSign == '/')
                    v.back() /= dgt;

                cout << "end, i: " << i << endl;
                dgt = 0;
                --i;
                // 此处的--i非常重要，因为在寻找dgt的步骤中，最后一步有i++，所以目前的i停留在运算符号上
                // 因为每一遍循环结束之后，for语句也要做一遍i++，所以当下一次循环开始的时候，i已经跳过了符号，直接停在了下一个数字上
                // 那么对于字符串而言，就变成了全部是加法运算

                // 除了--i之外，还可以使用while循环，while循环不会在循环结束的时候+1，此处的--i就可以删去
                // 但是使用while的时候，需要考虑到如果s[i]是运算符号，那么就不会走到最后的else，那么就没有语句能让i增加，就变成了死循环
                // 所以要在第二种情况，即，遍历到的char是个符号的时候，再++i，往后走一位，开始搜索数字
            }
            printVec(v);
        }
        return accumulate(v.begin(), v.end(), 0);
        // accumulate需要添加<numeric>标准库
    }

    void printVec(vector<int> nums)
    {
        for (auto c : nums)
        {
            cout << c << " ";
        }
        cout << endl;
    }
};

class Test
{
public:
    void string2int(string s)
    {
        s = "123";
        int sint = atoi(s.c_str());
        cout << sint;
        istringstream sstr("1234");
        int i;
        sstr >> i;
        cout << i;
        string sss = "234";
        s = s + s[0];
        sint = atoi(s.c_str());
        cout << sint;
    }

    void switch_test()
    {
        string s = "1/1/12";
        for (auto c : s)
        {
            switch (c)
            {
            case '/':
                cout << "/" << endl;
            case '1':
                cout << c << endl;
            case '2':
                cout << "2" << endl;
            default:
                break;
            }
        }
        cout << "case end" << endl;

        for (auto c : s)
        {
            if (c == '1')
                cout << c << endl;
            if (c == '/')
                cout << c << endl;
            if (c == '2')
                cout << c << endl;
        }
    }

    void is_digit_test()
    {
        string s = "123sdf";
        for (auto c : s)
        {
            if (isdigit(c))
            {
                cout << c << endl;
            }
            else
            {
                cout << "not digit" << endl;
            }
        }
    }
};

int main()
{
    Solution sol;
    string s = "3+2/3+332+25+6-1";
    sol.calculate(s);
}