#include<iostream>
using namespace std;

class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        int res, prev = 0, curr = 1;
        while (n-- > 1)
        {
            res = prev + curr;
            prev = curr;
            curr = res;
        }
        return res;
    }
};

int main(){
    Solution sol;
    cout << sol.fib(153);
}