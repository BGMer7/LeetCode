#include <map>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    map<int, int> m;
    vector<int> nums{4, 2, 6, 3, 7, 5, 3, 5, 1, 2, 6};
    for (int i = 0; i < nums.size(); i++)
        m.insert({nums[i], i});

    cout << m[4] << endl;
    if (m[13])
        cout << m[13] << endl;
    else
        cout << "no such number";
}