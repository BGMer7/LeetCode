#include <string>
#include <iostream>

using namespace std;

class Solution
{
private:
    int count = 0;

public:
    string name = "PublicName";

    int countSubstrings(string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            centerSpread(s, i, i);
            centerSpread(s, i, i + 1);
        }
        return count;
    }

    void centerSpread(string s, int left, int right)
    {
        while (left >= 0 && right <s.size())
        {
            if (s[left] != s[right])
            {
                return;
            }
            else
            {
                ++count;
                --left;
                ++right;
            }
        }
    }
};

int main()
{
    Solution sol;
    cout << sol.name <<endl;
    cout << sol.countSubstrings("abc");
}