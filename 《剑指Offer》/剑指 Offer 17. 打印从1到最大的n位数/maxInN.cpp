#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> printNumbers(int n)
    {
        int maxNum = 1;
        n = n + 1;
        while (--n)
            maxNum *= 10;
        vector<int> res;
        int i = 1;
        while (i < maxNum)
            res.push_back(i++);
        return res;
    }
};

int main() {}