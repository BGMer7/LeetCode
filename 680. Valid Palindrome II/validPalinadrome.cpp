#include <iostream>

using namespace std;

class Solution
{
public:
    bool validPalindrome(string s)
    {
        int i = 0;
        int j = s.size() - 1;
        int cnt = 1;
        while (i <= j)
        {
            if (s[i] == s[j])
            {
                ++i;
                --j;
            }
            else if (s[i + 1] == s[j] && cnt > 0)
            {
                ++i;
                --cnt;
            }
            else if (s[i] == s[j - 1] && cnt > 0)
            {
                --j;
                --cnt;
            }
            else
            {
                return false;
            }
            cout << i << ":" << s[i] << " " << j << " j:" << s[j] << endl;
        }

        return true;
    }
};

class SolutionTwo
{
public:
    bool isValidPalinadrome(string s, int i, int j)
    {
        while (i <= j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            else
            {
                ++i;
                --j;
            }
        }
        return true;
    }

    bool validPalindrome(string s)
    {
        for (int i = 0, j = s.size() - 1; i <= j; ++i, --j)
        {
            if (s[i] != s[j])
                return isValidPalinadrome(s, i, j - 1) || isValidPalinadrome(s, i + 1, j);
        }
        return true;
    }
};

class Solution
{
public:
    bool validPalindrome(string s)
    {
        int n = s.length();
        for (int i = 0, j = n - 1; i < j; i++, j--)
        {
            if (s[i] != s[j])
            {
                return isHw(s, i, j - 1) || isHw(s, i + 1, j);
            }
        }
        return true;
    }
    bool isHw(string s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

main()
{
    // "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga"
    string s("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga");
    Solution sol;
    SolutionTwo sol2;
    bool res = sol.validPalindrome(s);
    bool res2 = sol.validPalindrome(s);
    cout << res << endl;
    cout << res << endl;
}