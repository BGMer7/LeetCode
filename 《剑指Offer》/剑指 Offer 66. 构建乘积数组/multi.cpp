#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> constructArr(vector<int> &a)
    {
        vector<int> res(a.size());
        for (int i = 0, ans = 1; i < a.size(); ans *= a[i], i++)
            res[i] = ans;
        for (int i = a.size() - 1, ans = 1; i >= 0; ans *= a[i], i--)
            res[i] *= ans;
        return res;
    }
};

int main() {}