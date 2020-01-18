#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    string convert(string s, int numRows)
    {
        int size = s.length();
        if (numRows==1)
            return s;
        vector<string> row(min(numRows, size));
        int curRow=0;
        bool isDown = false;
        for (char c : s)
        {
            row[curRow] += c;
            if ((numRows - 1) == curRow || curRow == 0)
                isDown = !isDown;          //如果触底或者触顶，就方向反转
            curRow += ((isDown) ? 1 : -1); //如果是down，curRow就要自减，如果不是down就是自加
        }
        string res;
        for (string rows : row)
        {
            res += rows;
        }
        return res;
    }
};

int main()
{
    string s("ajysgfdkuyeqwbfvcjsdhgfukdsfgksaytcgd8suywieuqrgqrqwkvbsajhagsdkvjsahgfkyqetruiybvsafdjhb");
    Solution sol;
    cout << sol.convert(s, 1) << endl;
}