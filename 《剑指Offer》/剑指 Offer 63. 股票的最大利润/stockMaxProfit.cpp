#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0;
        int lowestPrice = INT_MAX;
        for (auto pri : prices)
        {
            if (pri < lowestPrice)
                lowestPrice = pri;
            maxProfit = max(maxProfit, pri - lowestPrice);
        }
        return maxProfit;
    }
};

int main() {}