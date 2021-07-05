#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0;
        int lowest = INT_MAX;
        for (auto price : prices)
        {
            if (price < lowest)
                lowest = price;
            else
                maxProfit = max(maxProfit, price - lowest);
        }
        return maxProfit;
    }
};

class StockCommonSolution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buy = INT_MIN;
        int sell = 0;
        // 其实buy和sell的变量代表的是今天开始的时候手头有的钱，和今天结束的时候手头有的钱，始终要使手里钱最多
        for (int p : prices)
        {
            buy = max(buy, -p);        // (没有买，在今天的价格买了股票)
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