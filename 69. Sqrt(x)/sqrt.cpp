#include <iostream>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
            return 0;
        int i = 0;
        int j = x;
        int ans;
        long long mid = i + (j - i) / 2;
        while (i <= j)
        {
            mid = i + (j - i) / 2;
            if (mid * mid <= x)
            {
                ans = mid;
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
            cout << i << " " << j << " " << mid << endl;
        }
        return mid;
    }

    int hisSqrt(int x){
        int l = 0, r = x, ans = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x)
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans;

    }
};

int main()
{

    int x = 256;
    Solution sol;
    cout << sol.mySqrt(x) << endl;
    cout << sol.hisSqrt(x) << endl;
}