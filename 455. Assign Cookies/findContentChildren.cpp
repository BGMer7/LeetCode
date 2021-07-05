#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &children, vector<int> &cookies)
    {
        if (cookies.size() == 0)
            return 0;
        sort(children.begin(), children.end());
        sort(cookies.begin(), cookies.end());
        int child = 0;
        int cookie = 0;
        while (child < children.size() && cookie < cookies.size())
        {
            if (children[child] <= cookies[cookie])
            {
                child++;
            }
            cookie++;
        }
        return child;
    }
};

class Print
{
public:
    void printVectorinSort(vector<int> &vector)
    {
        sort(vector.begin(), vector.end());
        for (int i = 0; i < vector.size(); i++)
        {
            cout << vector[i] << " ";
        }
        cout << endl;
    }
};

int
main()
{
    // vector<int> testVec{1, 2, 36, 5, 4, 6, 4, 6, 87, 32, 34, 54, 54, 64, 6, 45};
    // sort(testVec.begin(), testVec.end());
    // for (int i = 0; i < testVec.size(); i++)
    // {
    //     cout << testVec[i] << " ";
    // }
    vector<int> children{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> cookies1{3, 242, 4, 32, 24, 2, 42, 423, 4, 2, 5, 23, 42, 453, 623, 434, 3, 2, 2343, 24, 23, 4, 324, 345, 3, 24, 2342, 423, 45, 3645, 343};
    vector<int> cookies2{3, 4, 2, 6, 3, 6, 8, 3, 1, 2};
    Solution sol;
    Print print;
    print.printVectorinSort(cookies1);
    print.printVectorinSort(cookies2);
    int res1 = sol.findContentChildren(children, cookies1);
    int res2 = sol.findContentChildren(children, cookies2);
    cout << res1 << " " << res2;
}