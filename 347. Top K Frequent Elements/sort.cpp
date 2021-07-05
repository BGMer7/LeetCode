#include <algorithm>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

bool cmp1(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first; //对于first的升序
}
bool cmp2(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second; //对于second的升序
}
bool rule(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}
int main()
{
    map<int, int> hash;
    hash[1] = 4;
    hash[3] = 3;
    hash[2] = 5;
    hash[4] = 1;
    vector<pair<int, int>> vecs;
    for (auto it = hash.begin(); it != hash.end(); it++)
    {
        vecs.push_back(make_pair(it->first, it->second));
    }
    //对于first升序排列
    cout << "对于first升序排列:" << endl;
    sort(vecs.begin(), vecs.end(), rule);
    for (auto it = vecs.begin(); it != vecs.end(); it++)
        cout << it->first << ':' << it->second << '\n';
    //对于second升序排列
    cout << "对于second升序排列:" << endl;
    sort(vecs.begin(), vecs.end(), rule);
    for (auto it = vecs.begin(); it != vecs.end(); it++)
        cout << it->first << ':' << it->second << '\n';


    vector<int> nums;
    int k = 2;
    int n = nums.size();
    int max = INT_MIN;
    int min = INT_MAX;
    for (auto c : nums)
    {
        if (c > max)
            max = c;
        if (c < min)
            min = c;
    }
    int bucketNum = (max - min) + 1;
    vector<int> buckets(bucketNum);
    for (int i = 0; i < n; i++)
    {
        buckets[nums[i] - min]++;
    }
    vector<pair<int, int>> freq2num;
    for (int i = 0; i < buckets.size(); i++)
    {
        freq2num.push_back(make_pair(buckets[i], i + 1));
    }
    // cout << freq2num[0].first << " " << freq2num[0].second << endl;
    sort(freq2num.begin(), freq2num.end());
    // cout << freq2num[3].first << " " << freq2num[3].second << endl;
    vector<int> res{};

    int i = freq2num.size() - 1;
    while (k > 0)
    {
        int num = freq2num[i].second;
        res.push_back(num);
        --k;
        --i;
    }

    return 0;
}
