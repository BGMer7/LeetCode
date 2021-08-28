#include <string>
#include <iostream>
using namespace std;

class Solution
{
private:
    bool countChar(string &s)
    {
        int cntL = 0;
        for (char c : s)
        {
            if (c == 'L')
                ++cntL;
            if (cntL == 3)
                return false;
        }
        return true;
    }

public:
    bool checkRecord(string s)
    {
        const int len = s.size();
        int cntA = 0;
        for (int i(0); i < len; ++i)
        {
            if (s[i] == 'A')
                ++cntA;
            if (cntA >= 2)
                return false;
            string sub = s.substr(i, 3);
            if (!countChar(sub))
                return false;
        }
        return true;
    }
};

int main() {
    string s("ALLPPPP");
    cout << s.substr(6,3);
}