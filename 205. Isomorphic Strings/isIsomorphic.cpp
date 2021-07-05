#include <unordered_map>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        unordered_map<char, char> charMap1, charMap2;
        for (int i = 0; i < s.size(); i++)
        {
            if (!charMap1[s[i]])
            {
                charMap1[s[i]] = t[i];
                // cout << "null" << charMap[s[i]] << endl;
            }
            else if (charMap1[s[i]] != t[i])
            {
                // cout << "not" << endl;
                return false;
            }
        }
        string temp;
        temp = s;
        s= t;
        t=temp;
        for (int i = 0; i < s.size(); i++)
        {
            if (!charMap2[s[i]])
            {
                charMap2[s[i]] = t[i];
                // cout << "null" << charMap[s[i]] << endl;
            }
            else if (charMap2[s[i]] != t[i])
            {
                // cout << "not" << endl;
                return false;
            }
        }
        return true;
    }
};

int main()
{
    string s("asdfgg");
    string t("zxcvba");
    // cout << s.size() << endl;
    // cout << t.size() << endl;
    // cout << s.length() << endl;
    // cout << t.length() << endl;
    // unordered_map<char, char> charMap;
    // for (int i = 0; i < s.size(); i++)
    // {
    //     charMap[s[i]] = t[i];
    // }

    // if (!charMap['c'])
    // {
    //     cout << "yes" << endl;
    // }
    // //cout << charMap['c'] << endl;
    // cout << charMap['a'] << endl;
    Solution sol;
    cout << sol.isIsomorphic(s, t);
}