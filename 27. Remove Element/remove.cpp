#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int i = 0;
		for (int j = 0; j < nums.size(); j++) {
			if (nums[j] != val) {
				nums[i] = nums[j];
				i++;
			}
		}
	}
};

int main() {
	vector<int> res = {1};
	bool b = res[0] == NULL;
	cout << b << endl;
}