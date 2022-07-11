#include <vector>

using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res = vector<int>(2*n);
        int x = 0;
        int y = n;
        for (int i = 0; i<2*n;i) {
            res[i++] = nums[x++];
            res[i++] = nums[y++];
        }
        return res;
    }
};

int main() {}