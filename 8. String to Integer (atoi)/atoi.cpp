#include<iostream>
#include<sstream>
#include<string>

using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int res = 0;
		istringstream is(str);
		//leetcode��������ķ���������istringstream���÷���Primer��P287
		is >> res;
		//�����Ǻ��������Ĺ�����������
		return res;
	}
};

int main() {
	string str("3424vs7dalidgb783r23");
	Solution s;
	int res = s.myAtoi(str);
	cout << res << endl;

}