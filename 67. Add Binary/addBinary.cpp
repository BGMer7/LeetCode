#include <istream>
#include <string>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int carry = 0;
        int m = a.size(), n = b.size();
        int diff = a - b;
        if (diff > 0)
        {
            string zero(diff, '0');
            b = zero + b;
        }
        if (diff < 0)
        {
            string zero(diff, '0');
            a = zero + a;
        }
        int len = max(a, b);
        string res(len, '0');
        for (int i(len - 1); i >= 0; --i)
        {
            int dig = a[i] + b[i] + carry;
            if (dig > 1)
            {
                carry = 1;
                res[i] = dig % 2;
            }
            else
            {
                carry = 0;
                res[i] = dig;
            }
        }
        if (carry == 1)
            res = '1' + res;
        return res;
    }
};