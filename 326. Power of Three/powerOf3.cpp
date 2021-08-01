#include <string>
#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        double x = log(n)/log(3);
        return x == floor(x);
    }
};

int main() {
    double x = log(243)/log(3);
    cout << x << endl;
    cout << (int)x << endl;
    cout << floor(x) << endl;
    

    double y = 5.12;
    cout << y << endl;
    
}