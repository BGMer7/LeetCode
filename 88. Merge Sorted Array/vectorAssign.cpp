#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> a{1, 3, 4, 6, 7, 0, 0, 0, 0};
    vector<int> b{2, 2, 3, 5};
    a.assign(b.begin(), b.begin() + 4);
    cout << a[4] << endl;
}