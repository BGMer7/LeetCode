#include <iostream>
#include <set>

using namespace std;

class Solution
{
    set<char> dict{'a', 'o', 'e', 'i', 'u', 'A', 'O', 'E', 'I', 'U'};

public:
    string reverseVowels(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            while (!dict.count(s[i]) && i < j)
                i++;
            while (!dict.count(s[j]) && i < j)
                j--;
            if (i < j)
                swap(s[i++], s[j--]);
        }
        return s;
    }
};

int main()
{
    string s("eeeooo");
    Solution sol;
    cout << sol.reverseVowels(s);
}