#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution
{
public:
	int myAtoi(string s)
	{
		int length = s.size();
		if (length == 0)
			return 0;
		if (length == 1)
			return s[0] - '0';
		int i = 0;
		while (i < length && s[i] == ' ')
			++i;
		int sign = 1;
		if (s[i] == '-')
		{
			sign = -1;
			++i;
		}
		if (s[i] == '+')
			++i;

		long long res = 0;
		while (i < length)
		{
			int digit = s[i] - '0';
			res = res * 10 + digit;
			bool stop = tooLarge(res * sign);
			if (stop)
				return sign == 1 ? INT_MAX : INT_MIN;

			++i;
		}
		return res * sign;
	}

private:
	bool tooLarge(long long res)
	{
		return res >= INT_MAX || res <= INT_MIN;
	}
};

int main()
{
	string str("    -3424");
	Solution s;
	int res = s.myAtoi(str);
	cout << res << endl;
}