#include <vector>
#include <iostream>

using namespace std;

class StockCommonSolution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buy = INT_MIN;
        int sell = 0;
        for (int p : prices)
        {
            buy = max(buy, sell-p);        // (没有买，在今天的价格买了股票)
            sell = max(sell, buy + p); // （没有卖，在今天的价格卖了股票）
        }
        return sell;
    }
};

int main()
{
    vector<int> prices{7, 1, 5, 3, 6, 4};
    StockCommonSolution sol;
    cout << sol.maxProfit(prices) << endl;
}