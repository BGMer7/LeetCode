#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
/*
label = 14
14/2 = 7 odd reverse
7/2 = 3 even
3/2 = 1 odd reverse

label = 11
11/2 = 5 odd reverse
5/2 = 2 even
2/2 = 1 odd reverse

label = 6
6/2 = 3 even
3/2 = 1 odd 


*/

class Solution
{
private:
    int mirror(int num, int depth)
    {
        return pow(2, depth - 1) + pow(2, depth) - 1 - num;
    }

public:
    vector<int> pathInZigZagTree(int label)
    {
        int depth = 1;
        while (pow(2, depth) - 1 < label)
        {
            ++depth;
        }
        // cout << depth << endl;
        // cout << label << endl;
        if (depth % 2 == 0)
        {
            label = mirror(label, depth);
        }
        vector<int> res;
        while (depth > 0)
        {
            if (depth % 2 == 1)
                res.push_back(label);
            else
                res.push_back(mirror(label, depth));
            label /= 2;
            --depth;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {}