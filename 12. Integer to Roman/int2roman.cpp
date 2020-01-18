#include <map>
#include <iostream>
using namespace std;
class Solution
{
public:
    string int2Roman(int num)
    {
        map<int, string> transMap = {{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};

        string res;

        map<int, string>::reverse_iterator i = transMap.rbegin();
        while (i != transMap.rend())
        {
            if (num >= i->first)
            {
                res += i->second;
                num -= i->first;
            }
            else
                i++;
        }
        return res;
    }
};

int main()
{
    Solution s;
    string res;
    res = s.int2Roman(102);
    std::cout << res << "\n";
}