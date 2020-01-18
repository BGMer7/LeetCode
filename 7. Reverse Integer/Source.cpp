#include <iostream>
using namespace std;

const int int_max = 0x7ffffff;
//INT_MAX�Ѿ��Ƕ���Ϊ�ؼ��֣���ֵ��0x7fffffffһ��Ϊ2147483648

class Solution
{
public:
	int revserse(int num)
	{
		int rev = 0;
		while (num != 0)
		{
			int pop = num % 10;
			num /= 10;
			//ÿ�ΰ����һλ������ɾ��
			if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
				return 0;
			if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
				return 0;
			rev = rev * 10 + pop;
		}
		return rev;
	}
};

int main()
{
	int num = 12345678;
	int remain = num;
	while (remain > 0)
	{
		cout << remain << " ";
		int number = remain % 10;
		cout << number << endl;
		remain = remain / 10;
	}
}