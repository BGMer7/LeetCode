#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		// this method can only return the nums of the different nums
		// the nums vector is not changed however
		int counter = 0;
		int n = nums.size();
		if (n == 0) return 0;
		for (int i = 0; i < n; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			else {
				counter++;
			}
		}
		return counter;
	}
	
	int removeDuplicatesVector(vector<int>& nums) {
		// this method change the nums like
		// {0,1,2,2,2,3,3,4,5,6} -> {0,1,2,3,4,5,6,4,5,6}
		// the length of the original vector has no changes
		// using the nums returns, only the first i elements can be showed
		int i = 0;
		int j = 1;
		if (nums.size() < 2) return nums.size();
		while (j < nums.size())
		{
			if (nums[i] != nums[j]) {
				nums[++i] = nums[j];
			}
			j++;
		}
		return i + 1;
	}
};

int main() {
	Solution s;
	vector<int> nums{ 0,1,2,3,3,3,3,3,4,5,6,7,8,9,9,9,9 };
	int res = s.removeDuplicates(nums);
	cout <<"the length of the new vector without duplicates: " << res << endl;
	cout << "---------------------------------------------------" << endl;
	int resVec = s.removeDuplicatesVector(nums);
	cout << "the length of the new vector without duplicates: " << resVec << endl;
	cout << "and the new vector can be showed: " << endl;
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
		cout << (*it) << ' ';
	}
	cout << "\n---------------------------------------------------" << endl;
	vector<int> test{ 0,1,2,3,4,5,6,6,7,8,8,8 };
	test[7] = test[9];
	cout << "test how to change the vector: " << endl;
	for (vector<int>::iterator it = test.begin(); it != test.end(); it++) {
		cout << (*it) << ' ';
	}
	cout << "\n---------------------------------------------------" << endl;
}