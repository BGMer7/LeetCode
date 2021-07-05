#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int len = digits.size();
        int carry = 0;
        digits[len - 1] += 1;
        for (int i = len - 1; i > 0; --i)
        {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
        digits[0] += carry;
        if (digits[0] >= 10)
        {
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

class SolutionString // 阿里云面试6.24，string类型加1
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 1;
        int n = digits.size();
        for (int i(n - 1); i > 0; --i)
        {
            int digit = digits[i];
            digit += carry;
            carry = digit / 10;
            digit = digit % 10;
            cout << digit << endl;
            digits[i] = digit;
        }

        cout << "res";
        if (carry == 1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 1;
        int n = digits.size();
        for (int i(n - 1); i >= 0; --i)
        {
            int digit = digits[i];
            digit += carry;
            carry = digit / 10;
            digit %= 10;
            digits[i] = digit;
        }

        if (carry == 1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main(){
    vector<int> nums{9};
    Solution sol;
    sol.plusOne(nums);
    plusOne(nums);
    cout << 10%10 << endl;
}