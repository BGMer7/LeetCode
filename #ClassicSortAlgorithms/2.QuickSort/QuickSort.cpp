/*
快速排序的基本思想：
通过一趟排序将待排记录分隔成独立的两部分，
其中一部分记录的关键字均比另一部分的关键字小，
则可分别对这两部分记录继续进行排序，以达到整个序列有序。
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void print_vector(vector<int> nums)
{
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "--------------------------------" << endl;
}

int partition1(vector<int> &nums, int start, int end)
{
	int base = nums[start];			   // set the first element as the pivot
	int left = start + 1, right = end; // why need +1? -> the nums[start] has been used as the pivot
	while (left <= right)
	{
		if (nums[left] < base)
			left++; // the first left element which is < base comes out
		else if (nums[right] > base)
			right--; // the first right element which is > base comes out
		else if (nums[left] >= base && nums[right] <= base)
			swap(nums[left++], nums[right--]); // equal to "swap(nums[left], nums[right])";left++;right--;"
	}
	cout << "right: " << right << " start: " << start << endl;
	cout << "swaped " << nums[start] << " " << nums[right] << endl;
	swap(nums[right], nums[start]); // not quite understand
	print_vector(nums);
	return right;
}

int partition2(vector<int> &nums, int start, int end)
{
	int base = nums[start];
	int index = start + 1;
	for (int i = index; i <= end; i++)
	{
		if (nums[i] < base)
		{
			swap(nums[i], nums[index++]);
		}
	}
	swap(nums[start], nums[index - 1]);
	return index - 1;
}

void quick_sort(vector<int> &nums, int start, int end)
{
	if (start < end)
	{
		int base = partition1(nums, start, end);
		// int pivot = partition2(arr,beg,end);
		quick_sort(nums, start, base - 1);
		quick_sort(nums, base + 1, end);
	}
}

int main()
{
	vector<int> nums{6, 324, 4, 3, 42, 5, 34, 2, 23};
	print_vector(nums);
	quick_sort(nums, 0, nums.size() - 1);
	print_vector(nums);
	vector<int> test{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	swap(test[0], test[1]);
	cout << test[0];
}
