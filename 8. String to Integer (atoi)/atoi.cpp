#include<iostream>
#include<sstream>
#include<string>

using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int res = 0;
		istringstream is(str);
		//leetcode网友提出的方法，关于istringstream的用法在Primer的P287
		is >> res;
		//还不是很清楚这个的规则是怎样的
		return res;
	}
};

int main() {
	string str("3424vs7dalidgb783r23");
	Solution s;
	int res = s.myAtoi(str);
	cout << res << endl;

}