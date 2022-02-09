#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        int index = word.find(ch);
        if (index < 0)
            return word;

        reverse(word.begin(), word.begin() + index);
    }
};