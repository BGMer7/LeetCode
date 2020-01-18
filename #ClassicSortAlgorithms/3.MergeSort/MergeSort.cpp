#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

void vec_printer(vector<int> nums) {
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
}

vector<int> merge(vector<int> a, vector<int> b) {
	vector<int> res;
	int a_ptr = 0;
	int b_ptr = 0;
	while (a_ptr < a.size() && b_ptr < b.size()) {
		if (a[a_ptr] < b[b_ptr]) {
			res.push_back(a[a_ptr++]);
			vec_printer(res);
		}
		else if (a[a_ptr] > b[b_ptr]) {
			res.push_back(b[b_ptr++]);
			vec_printer(res);
		}
		else if (a[a_ptr] = b[b_ptr]) {
			res.push_back(a[a_ptr++]);
			res.push_back(b[b_ptr++]);
			vec_printer(res);
		}
	}
	if (a_ptr == a.size()) {
		while (b_ptr < b.size()) res.push_back(b[b_ptr++]);
		vec_printer(res);
	}
	else if (b_ptr == b.size()) {
		while (a_ptr < a.size()) res.push_back(a[a_ptr++]);
		vec_printer(res);
	}
	return res;
}

vector<int> merge_sort(vector<int> arr) {
	int n = arr.size();
	if (n < 2) return arr;
	int mid = n / 2;
	vector<int> front_part(arr.begin(), arr.begin() + mid);
	vector<int> back_part(arr.begin() + mid, arr.end());
	vec_printer(arr);
	return merge(merge_sort(front_part), merge_sort(back_part));
}

int main() {
	vector<int> nums{
		7,34,5,435,343,54,52,5,3,4,7,32,5,54,22,6,67,34,547,456,34,345,42,3425,436,453,544,5456,354,5434,463,4534,3457,6835,546,234
	};
	vector<int> res = merge_sort(nums);
	vec_printer(res);
}