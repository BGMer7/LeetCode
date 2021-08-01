#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;


class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        reverse(columnTitle.begin(), columnTitle.end());
        long len = columnTitle.size(), res = 0, level = 1;
        for (int i(0); i < len; ++i)
        {
            char c = columnTitle[i];
            int bit = c - 64;
            res = bit * level + res;
            level *= 26;
        }
        return res;
    }
};

int main() {}