#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int search(vector<int> &nums, int target)
	{
		// nums = { 4,1,2,3 };
		int size = nums.size();
		if (size == 0)
			return -1;
		if (size == 1 && nums[0] != target)
			return -1;
		else if (size == 1 && nums[0] == target)
			return 0;
		int i = 0;
		while (nums[i] < nums[i + 1] && i < size - 2)
			i++;
		int res = -1;
		if (nums[i + 1] == target)
		{
			res = i + 1;
		}
		else
		{
			res = binarySearch(nums, i + 2, size - 1, target);
			if (res == -1)
			{
				res = binarySearch(nums, 0, i, target);
			}
		}
		return res;
	}

private:
	int binarySearch(vector<int> nums, int left, int right, int target)
	{
		while (left <= right)
		{
			int middle = left + (right - left) / 2;
			if (nums[middle] == target)
				return middle;
			else if (nums[middle] < target)
				left = middle + 1;
			else if (nums[middle] > target)
				right = middle - 1;
		}
		return -1;
	}
};

class SolutionNew
{
private:
	int binarySearch(vector<int> &nums, int target, int start, int end)
	{
		int left = start, right = end - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] < target)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return -1;
	}

public:
	int search(vector<int> &nums, int target)
	{
		int left = 0, right = nums.size() - 1;
		while (left < right)
		{
			int mid = left + (right - left) / 2;
			if (nums[mid] < nums[right])
				right = mid;
			else if (nums[mid] > nums[right])
				left = mid + 1;
			else
				--right;
		}
		cout << left << endl;
		int leftRes = binarySearch(nums, target, 0, left);
		int rightRes = binarySearch(nums, target, left, nums.size());

		cout << leftRes << " " << rightRes << endl;
		if (leftRes == -1 && rightRes == -1)
			return -1;
		else if (leftRes == -1)
			return rightRes;
		else
			return leftRes;
		return -1;
	}
};

int main()
{
	Solution s;
	vector<int> nums{1, 3};
	int res = s.search(nums, 0);
	cout << res << endl;
}