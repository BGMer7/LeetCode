#include <vector>
#include <iostream>

using namespace std;

int countPrimes(int n)
{
    if (n <= 2)
        return 0;
    vector<bool> prime(n, true);
    int count = n - 2; // 去掉不是质数的1
    for (int i = 2; i <= n; ++i)
    {
        if (prime[i])
        {
            for (int j = 2 * i; j < n; j += i)
            {
                if (prime[j])
                {
                    prime[j] = false;
                    --count;
                }
            }
        }
    }
    return count;
}

class Solution
{
public:
    int countPrimes(int n)
    {
        if (n < 3)
            return 0;
        int count = n / 2, i = 3, sqrtn = sqrt(n);
        vector<bool> prime(n, true);
        while (i <= sqrtn)
        {
            for (int j = i * i; j < n; j += 2 * i)
            {
                if (prime[j])
                {
                    prime[j] = false;
                    --count;
                }
            }
            do
            {
                i += 2;
            } while (i <= sqrtn && !prime[i]);
        }
        return count;
    }
};

int main()
{
    int i = 10;
    cout << countPrimes(5000000);
}