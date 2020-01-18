#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        bool res = false;
        int temp = x;
        if (x < 0)
            return false;

        int rev = 0;
        while (x != 0)
        {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
                return false;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
                return false;
            rev = rev * 10 + pop;
        }
        return rev == temp;
    }
};

class SolutionString
{
public:
    bool isPalindromeByString(int x)
    {
        bool res = true;
        string str_x = to_string(x);
        int len = str_x.length();
        int left = 0;
        int right = len - 1;
        while (left != right)
        {
            if (str_x[left] == str_x[right])
            {
                left++;
                right--;
            }
            else
            {
                res = false;
                break;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    int x = 1000000001;
    bool res = s.isPalindrome(x);
    cout << res << endl;
    SolutionString ss;
    res = ss.isPalindromeByString(x);
    cout << res << endl;
}