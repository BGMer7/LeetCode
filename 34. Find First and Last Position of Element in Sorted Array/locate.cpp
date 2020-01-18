#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int size = nums.size();
		vector<int> res{  };
		int index = binarySearch(nums, target);
		if (index == -1) {
			res.push_back(-1);
			res.push_back(-1);
			return res;
		}
		else {
			int start = index;
			int end = index;
			while (start > 0 && nums[start-1] == nums[index]) {
				// TMD我今天才发现（刚刚自己试验出来的）：(start>0 && nums[start-1]==nums[index])和(nums[start-1]==nums[index] && start>0)是不一样的
				// 但是仔细想想确实没问题，代码一行一行执行的，一行一行也是从左到右执行的，条件也是从左到右判断的，如果start>0的条件没有通过就不会执行nums[start-1]
				// 这样子就不会导致heap-over-flow了，以前天真了，一直觉得括号里执行的两个条件的话就会是一样的等级了，没想到括号里也分三六九等。
				start--;
				cout << "start:" << start << endl;
			}
			while (end < size - 1 && nums[end+1] == nums[index]) {
				end++;
				cout << "end" << end << endl;
			}
			res.push_back(start);
			res.push_back(end);
			return res;
		}
	}

private:
	int binarySearch(vector<int> nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right) {
			int middle = left + (right - left) / 2;
			if (nums[middle] == target) return middle;
			else if (nums[middle] < target) left = middle + 1;
			else if (nums[middle] > target)	right = middle - 1;
		}
		return -1;
	}
};

int main() {
	Solution s;
	int target = 1;
	vector<int> nums{ 1 };
	vector<int> res = s.searchRange(nums, target);
	cout << res[0] << " " << res[1] << endl;
}