#include <queue>
#include <deque>
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

int main() {}