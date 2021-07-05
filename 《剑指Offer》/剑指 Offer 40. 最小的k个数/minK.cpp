#include <vector>
#include <algorithm>

using namespace std;

class SolutionHeap
{
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        int n = arr.size();
        for (int i((n - 1) / 2); i >= 0; --i)
        {
            heapAdjust(i, n - 1, arr);
        }
        vector<int> res;
        for (int i(n - 1); i > n - 1 - k; --i)
        {
            res.push_back(arr[0]);
            // cout << arr[0];
            swap(arr[0], arr[i]);
            heapAdjust(0, i - 1, arr);
        }
        return res;
    }

    void heapAdjust(int left, int right, vector<int> &arr)
    {
        int dad = left, son = 2 * dad + 1;
        while (son <= right)
        {
            if (son + 1 <= right && arr[son] > arr[son + 1])
                son = son + 1;
            if (arr[dad] < arr[son])
                return;
            else
            {
                swap(arr[dad], arr[son]);
                dad = son;
                son = 2 * dad + 1;
            }
        }
    }
};

class SolutionSort
{
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        arr.resize(k);
        return arr;
    }
};

int main() {}