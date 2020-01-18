#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

void vec_printer(vector<int> nums) {
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " " ;
	}
	cout << endl;
}

void insert_sort(vector<int>& nums) {
	int n = nums.size();
	for (int i = 1; i < n; i++) {
		//������ؽ�i����Ϊ1���������nums����С��1Ҳ���ù��ˡ�������Ҫ������n==0��n==1�����
		int current = nums[i];
		int ptr = i - 1;
		while (ptr >= 0 && nums[ptr] > current) {
			//����˴���ptrû������Ϊ>=0����ô��һ��Ԫ�ؾ�һֱ�޷�������
			//�������������Ѿ����������У����ԴӺ���ǰ�ҵĻ���Ҫ�ҵ���һ����currentС����������ֻҪ��current��ptr���Լ���
			nums[ptr + 1] = nums[ptr];
			ptr--;
			vec_printer(nums);
			cout << "current: " << current << endl;
		}
		cout << endl;
		nums[ptr + 1] = current;
	}
}

void insertion1(vector<int>& arr) {
	for (int i = 1; i < arr.size(); i++) {
		int temp = arr[i];
		int j = i - 1;
		for (; j >= 0 && temp < arr[j]; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}


int main() {
	vector<int> nums{ 16,84,65,14,5,6,43,21,35,48,4,1,56,7,68,9,41,6,34,1,8,7,45,13,2,41,6,89,741,8,745,6,3,121,98,7,45,1,3,54 };
	insert_sort(nums);
	vec_printer(nums);
	vector<int> sort_nums{ 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
	insert_sort(sort_nums);
	vec_printer(nums);
}