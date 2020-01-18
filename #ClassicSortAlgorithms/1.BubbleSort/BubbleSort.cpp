/*
ð��������һ�ּ򵥵������㷨��
���ظ����߷ù�Ҫ��������У�һ�αȽ�����Ԫ�أ�������ǵ�˳�����Ͱ����ǽ���������
�߷����еĹ������ظ��ؽ���ֱ��û������Ҫ������Ҳ����˵�������Ѿ�������ɡ�
����㷨��������������ΪԽС��Ԫ�ػᾭ�ɽ������������������еĶ��ˡ�
*/

#include <iostream>
#include <vector>
using namespace std;

class BubbleSort
{
public:
	/*�Ƚ����ڵ�Ԫ�ء������һ���ȵڶ����󣬾ͽ�������������
	��ÿһ������Ԫ����ͬ���Ĺ������ӿ�ʼ��һ�Ե���β�����һ�ԣ�����������Ԫ��Ӧ�û�����������
	������е�Ԫ���ظ����ϵĲ��裬�������һ����
	�ظ�����1~3��ֱ��������ɡ�
	*/
	vector<int> bubble_sort(vector<int> nums)
	{
		// ����β���vector<int> nums��nums����ı䣬�����vector<int>& nums������ֱ�����ã�����numsҲ�ı���
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
	��һ��flag�жϵ�ǰ��vector�ǲ�����������Ѿ�����Ϳ���ֱ���˳�
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