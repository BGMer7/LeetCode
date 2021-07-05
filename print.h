#include <vector>
#include <iostream>
#include <list>

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

    std::ostream &operator<<(std::ostream &ostr, const std::list<int> &list)
    {
        for (auto &i : list)
        {
            ostr << " " << i;
        }
        return ostr;
    } // the offical usage to cout the list
}