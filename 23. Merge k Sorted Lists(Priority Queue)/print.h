#include <vector>
#include <iostream>

using namespace std;

class Print
{
public:
    void printVector(vector<int> nums)
    {
        for (auto n : nums)
        {
            cout << n << " ";
        }
        cout << endl;
    }
};