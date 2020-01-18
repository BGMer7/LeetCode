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
				// TMD�ҽ���ŷ��֣��ո��Լ���������ģ���(start>0 && nums[start-1]==nums[index])��(nums[start-1]==nums[index] && start>0)�ǲ�һ����
				// ������ϸ����ȷʵû���⣬����һ��һ��ִ�еģ�һ��һ��Ҳ�Ǵ�����ִ�еģ�����Ҳ�Ǵ������жϵģ����start>0������û��ͨ���Ͳ���ִ��nums[start-1]
				// �����ӾͲ��ᵼ��heap-over-flow�ˣ���ǰ�����ˣ�һֱ����������ִ�е����������Ļ��ͻ���һ���ĵȼ��ˣ�û�뵽������Ҳ�������ŵȡ�
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