#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int size = intervals.size();
        if (size < 2)
            return 0;
        //sort(intervals.begin(), intervals.end()); 简单的排序并不总是奏效
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            return a[1] < b[1];
        }); //需要在sort后面加一个函数
        int i = 0;
        int j = 1;
        int remove = 0;
        while (j < size)
        {
            if (intervals[i][1] > intervals[j][0])
            {
                remove++;
                j++;
                //cout << "true ";
            }
            else
            {
                i = j;
                j++;
                //cout << "false ";
            }
            //cout << "i: " << i << ", j: " << j << ", remove: " << remove << endl;
        }
        return remove;
    }
};

int main()
{
    vector<int> interval{};
    vector<vector<int>> vec1{{1, 3}, {2, 3}, {4, 7}, {4, 6}, {3, 5}};
    vector<vector<int>> vec2{{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    vector<vector<int>> vec3{{1, 2}, {1, 2}, {1, 2}};
    vector<vector<int>> vec4{{1, 2}, {2, 3}};
    vector<vector<int>> vec5{{1, 2}};
    Solution sol;
    for (int i = 1; i < 6; i++)
    {
        string s = "vec" + i;
        int res = sol.eraseOverlapIntervals(1);
        cout << res << endl;
    }
    cout << res << endl;
}