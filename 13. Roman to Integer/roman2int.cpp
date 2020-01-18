#include <iostream>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<string, int> transmap = {{"I", 1},
                                               {"IV", 4},
                                               {"V", 5},
                                               {"IX", 9},
                                               {"X", 10},
                                               {"XL", 40},
                                               {"L", 50},
                                               {"XC", 90},
                                               {"C", 100},
                                               {"CD", 400},
                                               {"D", 500},
                                               {"CM", 900},
                                               {"M", 1000}};//map有问题，但是没完全懂

        int res = transmap[s.substr(0, 1)];
        cout << res<<endl;
        for (int i = 1; i < s.size(); ++i)
        {
            string two = s.substr(i - 1, 2);
            string one = s.substr(i, 1);
            res += transmap[two] ? transmap[two] : transmap[one];
            cout << res << endl;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    string s("IV");
    cout << sol.romanToInt(s);
}
