#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

void print(multiset<int> c)
{
    for (set<int>::iterator i = c.begin(); i != c.end(); i++)
        cout << *i << " ";
    cout << endl;
}

void print(vector<vector<int>> res) // 重载两个print函数，方便看结果
{
    for (auto c : res)
    {
        for (auto n : c)
            cout << n << " ";
        cout << endl;
    }
}

class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<pair<int, int>> coordenate; 
        for (auto c : buildings) //把原始数据拆开，用pair形式存储为点的坐标
        {
            coordenate.push_back(make_pair(c[0], -c[2]));
            coordenate.push_back(make_pair(c[1], c[2]));
        }
        sort(coordenate.begin(), coordenate.end()); // 根据x轴的坐标排序

        multiset<int> height; // 用来存储所有的高度
        height.insert(0); // 先插入一个0，因为所有height都大于0，所以不影响结果
        
        vector<vector<int>> res;
        for (auto i : coordenate)
        {
            int h = abs(i.second);
            if (i.second < 0) // 如果是左端点，就insert
            {
                if (h > *height.rbegin())
                    res.push_back({i.first, h});
                height.insert(-i.second);
            }
            if (i.second > 0) // 如果是右端点，就erase
            {
                height.erase(height.find(h));
                // 这是很精妙的一步，如果只是height.erase(h)，那么所有的h都会移除，如果存在两个楼都是h，那么另一个楼的数据也被移除了
                // 如果使用find函数的话，只会返回第一个h的index，再进行删除就确保最多只会删除一个
                if (h > *height.rbegin())
                    res.push_back({i.first, *height.rbegin()});
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> buildings{{2, 9, 10},
                                  {3, 7, 15},
                                  {5, 12, 12},
                                  {15, 20, 10},
                                  {19, 24, 8}};
    Solution sol;
    vector<vector<int>> res;
    res = sol.getSkyline(buildings);
    print(res);
}