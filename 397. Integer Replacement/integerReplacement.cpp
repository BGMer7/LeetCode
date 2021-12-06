#include <unordered_map>

using namespace std;

class Solution
{
public:
    int integerReplacement(int n)
    {
        if (n == 1)
            return 0;
        if (records.count(n))
            return records[n];
        if (!(n % 2))
        {
            records[n] = integerReplacement(n / 2) + 1;
            return records[n];
        }
        records[n] = min(integerReplacement(n / 2 + 1), integerReplacement((n - 1) / 2)) + 2;
        return records[n];
    }

private:
    unordered_map<int, int> records;
};

int main() {}