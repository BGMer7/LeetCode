#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		int n = nums.size();
		for (int i = 0; i < n - 2; i++) {
			if (nums[i] > 0) break;
			if (i > 0 && nums[i] == nums[i - 1]) continue;

			//Apply Binary search
			int left = i + 1;
			int right = n - 1;
			while (left < right) {
				//found a triplet
				//update left and right
				if (nums[i] + nums[left] + nums[right] == 0) {
					ans.push_back({ nums[i], nums[left], nums[right] });
					left++;
					right--;
					//avoid duplicates
					while (left < right && nums[left] == nums[left - 1]) left++;
					while (left < right && nums[right] == nums[right + 1]) right--;
				}
				else if (nums[i] + nums[left] + nums[right] < 0) {
					left++;
				}
				else {
					right--;
				}
			}
		}
		return ans;
	}
};

int main()
{
	Solution s;
	int a[6] = { 1,-1,-3,3,0,6 };
	vector<int> b;
	//将a的所有元素插入到b中
	b.insert(b.begin(), a, a + 7);
	vector<vector<int>> ans;
	ans = s.threeSum(b);
	cout << ans.size() << endl;
	for (vector<vector<int>>::iterator it = ans.begin(); it != ans.end(); ++it) {
		
		for (int i = 0; i < (*it).size(); ++i) {
			cout << (*it)[i] << " ";
		}
	}
}