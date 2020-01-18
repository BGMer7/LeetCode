/*
冒泡排序是一种简单的排序算法。
它重复地走访过要排序的数列，一次比较两个元素，如果它们的顺序错误就把它们交换过来。
走访数列的工作是重复地进行直到没有再需要交换，也就是说该数列已经排序完成。
这个算法的名字由来是因为越小的元素会经由交换慢慢“浮”到数列的顶端。
*/

#include <iostream>
#include <vector>
using namespace std;

class BubbleSort
{
public:
	/*比较相邻的元素。如果第一个比第二个大，就交换它们两个；
	对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对，这样在最后的元素应该会是最大的数；
	针对所有的元素重复以上的步骤，除了最后一个；
	重复步骤1~3，直到排序完成。
	*/
	vector<int> bubble_sort(vector<int> nums)
	{
		// 如果形参是vector<int> nums，nums不会改变，如果是vector<int>& nums，就是直接引用，所以nums也改变了
		if (nums.size() == 0 && nums.size() == 1)
			return nums;
		for (int i = 0; i < nums.size() - 1; i++)
		{
			for (int j = i; j < nums.size() - 1; j++)
			{
				if (nums[j] > nums[j + 1])
					swap(nums[j], nums[j + 1]);
			}
		}
		return nums;
	}

	/*
	用一个flag判断当前的vector是不是有序，如果已经有序就可以直接退出
	*/
	vector<int> optimized_bubble_sort(vector<int> nums)
	{
		bool flag = true;
		if (nums.size() == 0 && nums.size() == 1)
		{
			return nums;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i; j < nums.size(); j++)
			{
				if (nums[j] > nums[j + 1])
				{
					int temp = nums[j];
					nums[j] = nums[j + 1];
					nums[j + 1] = temp;
					flag = false;
				}
			}
			if (flag)
			{
				break;
			}
		}
		return nums;
	}
};

int main()
{
	BubbleSort s;
	vector<int> nums{1, 3, 2, 3, 3, 7, 5, 7, 5, 34, 7, 5, 5657, 43, 6, 45, 34, 56};
	cout << "the original nums vector:" << endl;
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
	cout << "-------------------------------------------" << endl;
	vector<int> res = s.bubble_sort(nums);

	cout << "the commom bubble sort:" << endl;
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
	cout << "-------------------------------------------" << endl;
	cout << "the optimized bubble sort:" << endl;
	vector<int> optimized_res = s.bubble_sort(nums);
	for (int i = 0; i < res.size(); i++)
	{
		cout << optimized_res[i] << " ";
	}
}