#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        int up = 0, down = m - 1;
        if (matrix[m - 1][0] < target)
            return binarySearch(0, n - 1, matrix[m - 1], target);
        while (up < down)
        {
            int mid = up + (down - up) / 2;
            if (matrix[mid][0] == target)
                return true;
            else if (matrix[mid][0] > target)
                down = mid;
            else if (matrix[mid][0] < target)
                up = mid + 1;
        }
        // cout << up;
        if (matrix[up][0] == target)
            return true;
        if (up == 0)
            return binarySearch(0, n - 1, matrix[0], target);

        return binarySearch(0, n - 1, matrix[up - 1], target);
    }

    bool binarySearch(int left, int right, vector<int> &matrix, int target)
    {
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (matrix[mid] == target)
                return true;
            else if (matrix[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};

int lowerBound(vector<int> nums, int target)
{
    int left = 0, right = nums.size() - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

bool bs(int left, int right, vector<int> &matrix, int target)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (matrix[mid] == target)
            return true;
        else if (matrix[mid] < target)
            left = mid+1;
        else
            right = mid-1;
    }
    return false;
}

int main() {
    vector<int> nums{10,11,16,20};
    int res = bs(0, 3, nums, 13);
    cout << res;
} 