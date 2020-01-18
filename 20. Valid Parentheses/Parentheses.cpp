#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        int size = s.size();
        if (s.size() == 0 || s.size() % 2 != 0)
            return false;
        for (int i = 0; i < 3; i++)
        {
            if (charStack.empty())
                charStack.push(s[i]);
            else
            {
                char top = charStack.top();
                if (check(top, s[i]))
                    charStack.pop();
                else
                    charStack.push(s[i]);
            }
        }
        return charStack.empty();
    }

private:
    stack<char> charStack;
    bool check(char c1, char c2)
    {
        if (c1 == '[' && c2 == ']' || c1 == '{' && c2 == '}' || c1 == '(' && c2 == ')')
            return true;
        else
            return false;
    }
};

main()
{
    string s = "{}[]";
    Solution sol;
    bool res;
    res = sol.isValid(s);
    cout << res << endl;
}