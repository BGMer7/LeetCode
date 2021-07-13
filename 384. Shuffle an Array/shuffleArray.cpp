#include <vector>
using namespace std;

class Solution
{
private:
    vector<int> origin;

public:
    Solution(vector<int> &nums)
    {
        origin = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        return origin;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        vector<int> data(origin);
        for (int i(0); i < origin.size(); ++i)
            swap(data[i], data[rand() % (i + 1)]);
        return data;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

int main() {}