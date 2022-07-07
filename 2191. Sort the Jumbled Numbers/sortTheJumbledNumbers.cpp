#include <utility>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <typeinfo>

using namespace std;

class Solution
{
private:
    // typedef pair<int, int> p;
    static bool cmp(pair<int, int> p1, pair<int, int> p2)
    {
        return p1.second < p2.second;
    }

public:
    int convert(vector<int> &mapping, int num)
    {
        int res = 0;
        int digit = 1;
        while (num)
        {
            res += mapping[num % 10] * digit;
            num /= 10;
            digit *= 10;
        }
        return res;
    }

    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
    {
        vector<pair<int, int>> container;
        for (int i = 0; i < nums.size(); ++i)
            container.push_back(make_pair(nums[i], convert(mapping, nums[i])));

        sort(container.begin(), container.end(), cmp);

        for (int i = 0; i < container.size(); ++i)
            nums[i] = container[i].first;

        return nums;
    }
};

void print(vector<int> nums)
{
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
}

Solution *createPtr()
{
    Solution *solPtr = new Solution();
    cout << "被函数创建的Solution指针：" << &solPtr << endl;
    delete solPtr;
    // 仍然可以输出
    // 我们在删除一个指针之后，编译器只会释放该指针所指向的内存空间，而不会删除这个指针本身。
    cout << "函数中被delete之后，指针的地址：" << &solPtr << endl;
    return solPtr;
}
