#include <queue>
#include <deque>
#include <vector>
using namespace std;

class MaxQueue
{
private:
    queue<int> q;
    deque<int> mq;

public:
    MaxQueue()
    {
    }

    int max_value()
    {
        if (mq.empty())
            return -1;
        return mq.front();
    }

    void push_back(int value)
    {
        q.push(value);
        while (!mq.empty() && mq.back() < value)
        {
            mq.pop_back();
        }
        mq.push_back(value);
    }

    int pop_front()
    {
        if (q.empty())
            return -1;
        int x = q.front();
        q.pop();
        if (x == mq.front())
            mq.pop_front();
        return x;
    }
};

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        MaxQueue mq;
        int i = 0;
        while (i < k)
            mq.push_back(nums[i]);
        vector<int> res;
        res.push_back(mq.max_value());
        for(i; i<nums.size(); i++) {
            mq.pop_front();
            mq.push_back();
            res.push_back(mq.max_value());
        }
        return res;
    }
};