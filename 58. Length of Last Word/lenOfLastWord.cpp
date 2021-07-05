#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        if (s == " ")
            return 0;

        while (s.size() != 0 && s[s.size() - 1] == ' ')
            s.pop_back();

        int len = 0;
        for (int i(s.size() - 1); i >= 0; --i)
        {
            if (s[i] != ' ')
                len++;
            else
                return len;
        }
        return len;
    }
};

int main()
{
    string s("      ");
    Solution sol;
    cout << sol.lengthOfLastWord(s);
}