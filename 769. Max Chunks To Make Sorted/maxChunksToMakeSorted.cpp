#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int max = arr[0];
        int count = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > max)
                max = arr[i];
            if (i >= max)
                ++count;
        }
        return count;
    }
};

int main()
{
}