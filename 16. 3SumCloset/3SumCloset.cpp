#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		vector<int> ans;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = 0; j < i; j++) {
				sum += nums[j];
			}
			ans.push_back(sum);
		}
		vector<int>::iterator q = min_element(ans.begin(),ans.end());
		return *q;
	}
};

class Solution1
{
public:
	int threeSumClosest(vector<int> &nums, int target)
	{
		//sort the nums vector
		sort(nums.begin(), nums.end());
		//initiate the int res
		int res = nums[0] + nums[1] + nums[2];
		for (int i = 0; i < nums.size(); i++)
		{
			int left = i + 1;
			int right = nums.size() - 1;
			while (left < right)
			{
				int sum = nums[left] + nums[i] + nums[right];
				if (abs(target - sum) < abs(target - res))
				{
					res = sum;
				}
				if (sum < target)
				{
					left++;
				}
				else if (sum > target)
				{
					right--;
				}
				else
				{
					return res;
				}
			}
		}
		return res;
	}
};

int main() {
	Solution1 s;
	int a[6] = { 1,-1,-3,3,0,6 };
	vector<int> b;
	//将a的所有元素插入到b中
	b.insert(b.begin(), a, a + 7);
}