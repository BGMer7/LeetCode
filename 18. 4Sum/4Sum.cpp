#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> res;
		int n = nums.size();
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n - 3; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			for (int j = i + 1; j < n - 2; j++) {
				if (j > i + 1 && nums[j] == nums[j - 1]) continue;
				int left = j + 1, right = n - 1;
				while (left < right) {
					int sum = nums[i] + nums[j] + nums[left] + nums[right];
					if (sum == target) {
						vector<int> out{ nums[i], nums[j], nums[left], nums[right] };
						res.push_back(out);
						while (left < right && nums[left] == nums[left + 1]) left++;
						while (left < right && nums[right] == nums[right - 1]) right--;
						left++; right--;
					}
					else if (sum < target) left++;
					else right--;
				}
			}
		}
		return res;
	}
};

int main() {
	Solution s;
	vector<int> t{ 1, 2, 3 };
	int a[8] = { 10, 24, 13, 12, -5, -2, 23, -10 };
	//通过数组a的地址初始化，注意地址是从0到5（左闭右开区间）
	vector<int> nums{1, 3, 7, -9, -5, -10 };
	vector<vector<int>> res = s.fourSum(nums, -5);
	cout << "the size of res is: " << res.size() << endl;
	for (vector<vector<int>>::iterator it = res.begin(); it != res.end(); it++) {
		for (int i = 0; i < (*it).size(); i++) {
			cout << (*it)[i] << " " << endl;
		}
	}
}