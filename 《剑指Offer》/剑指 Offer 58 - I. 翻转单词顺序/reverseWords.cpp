#include <stack>
#include <string>
#include <iostream>
using namespace std;

class Solution
{
private:
    stack<string> stk;

public:
    string reverseWords(string s)
    {
        string word("");
        s = s + ' ';
        for (auto ch : s)
        {
            if (ch == ' ')
            {
                if (word != "")
                    stk.push(word);
                word = "";
            }
            else
                word.push_back(ch);
        }
        cout << stk.size();
        string res("");
        while (!stk.empty())
        {
            cout << stk.top() << "1" << endl;
            res += (stk.top() + " ");
            stk.pop();
        }
        res.pop_back();
        return res;
    }
};

int main()
{
    string words("the sky is blue        ");
    Solution sol;
    cout << sol.reverseWords(words);
}