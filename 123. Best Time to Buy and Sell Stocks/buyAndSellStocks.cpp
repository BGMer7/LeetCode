#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int firstBuy = INT_MIN, firstSell = 0;
        int secondBuy = INT_MIN, secondSell = 0;
        for (int p : prices)
        {
            firstBuy = max(firstBuy, -p);
            firstSell = max(firstSell, firstBuy + p);
            secondBuy = max(secondBuy, firstSell - p);
            secondSell = max(secondSell, secondBuy + p);
        }
        return secondSell;
    }
};

int main()
{
    vector<int> prices{7, 1, 5, 3, 6, 4};
    Solution sol;
    cout << sol.maxProfit(prices) << endl;
}