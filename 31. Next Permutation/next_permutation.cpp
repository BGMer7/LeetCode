#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int i = 0;
		for (i = nums.size() - 2; i >= 0; i--) {
			if (nums[i] < nums[i + 1])break;
		}
		sort(nums.begin() + i + 1, nums.end());
		for (int j = i; j < nums.size(); j++) {
			if (nums[j] > nums[i]) {
				swap(nums[i], nums[j]);
				return;
			}
		}
	}

	void nextPermutation1(vector<int>& nums) {
		int size = nums.size();
		int i = size - 2;
		int j = size - 1;
		while (i >= 0 && nums[i] > nums[j]) {
			i++;
		}
		if (i > 0) {
			while (j >= 0 && nums[j] <= nums[i]) {
				j++;
			}
			swap(nums[i], nums[j]);
		}
	}
};


int main() {
	Solution s;
	vector<int> nums{ 1,2,3 };
	s.nextPermutation(nums);
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
		cout << *it << " ";
	}
	vector<int> nums1{ 1,2,3 };
	s.nextPermutation1(nums1);
	for (int i = 0; i < nums1.size(); i++) {
		cout << nums1[i] << " ";
	}

}