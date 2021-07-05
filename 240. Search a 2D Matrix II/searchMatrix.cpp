#include<vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
        }
        for (int i = 0; i < matrix.size(); i++)
        {
            bool res = binarySearch(matrix[i], target);
            if (res)
            {
                return true;
            }
            // cout << res << endl;
        }
        return false;
    }

    bool binarySearch(vector<int> nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (left <= right)
        {
            mid = (left + right) >> 1;
            // cout << "mid" << mid << endl;
            if (nums[mid] == target)
            {
                return true;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
        }
        return false;
    }
};

class SearchInPath
{
public:
    bool search_in_path(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        if (m == 1 && n == 1)
            return (matrix[0][0] == target);
        int row = 0;
        int column = n - 1;
        while (row < m && column >= 0)
        {
            if (matrix[row][column] > target)
            {
                --column;
            }
            else if (matrix[row][column] < target)
            {
                ++row;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

int main(){
    double n = 1.0000;
    double t = 1.05;
    int i=0;
    while(n<2.0000){
        ++i;
        n = t*n;
        cout << n << endl;
    }
    cout << n;
    cout << i;
}
