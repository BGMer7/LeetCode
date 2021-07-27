#include <cctype>
#include <string>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int left(0), right(s.size() - 1);
        while (left < right)
        {
            char chl = s[left], chr = s[right];
            if (chl < 65 || chl > 122 || (90 < chl && chl < 97)){
                ++left; continue;
            }
            if (chr < 65 || chr > 122 || (90 < chr && chr < 97)){
                --right; continue;
            }
            if (chl < 61)
                chl = toupper(chl);
            if (chr < 61)
                chr = toupper(chr);
            if(chl==chr) {
                ++left; --right;
            }else return false;
        }
        return true;
    }
};

class SolutionAPI
{
public:
    bool isPalindrome(string s)
    {
        int f = 0, r = s.size() - 1;
        while (f < r)
        {
            while (f < r && !isalnum(s[f]))
                f++;
            while (f < r && !isalnum(s[r]))
                r--;
            if (f < r)
            {
                if (toupper(s[f]) != toupper(s[r]))
                    return false;
                f++;
                r--;
            }
        }
        return true;
    }
};

int main() {}