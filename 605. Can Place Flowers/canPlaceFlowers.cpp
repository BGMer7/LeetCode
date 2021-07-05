#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;

// 每三块连续的土地就必定能种一颗花，因此只需要知道花坛中一共有多少个连续的三块土地即可。
// 然而于此而来的问题是花坛的头和尾可以在两块地的情况下种花。
// 为了解决这个问题，可以尝试扩充花坛的首尾，让原本的首尾被动成为可种花的位置。
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        // flowerbed = [0] + flowerbed + [0];
        flowerbed.insert(flowerbed.begin(), 1, 0); //在花坛的首尾加入空地
        flowerbed.insert(flowerbed.end(), 1, 0);
        int size = flowerbed.size();
        int i = 0;
        int contain = 0;
        while (i < size - 2)
        {
            if (flowerbed[i] == 0 && flowerbed[i + 1] == 0 && flowerbed[i + 2] == 0)
            {
                i = i + 2;
                contain++;
            }
            else
            {
                i++;
            }
            cout << contain << endl;
        }

        return contain >= n;
    }
};

int main()
{
    vector<int> flowerbed{0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0};
    Solution sol;
    bool res = sol.canPlaceFlowers(flowerbed, 2);
    cout << res << endl;
}