#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        const int len = nums.size();
        vector<int> res;
        int A=0, B=0, candi=0;
        int candiA=nums[0], candiB=nums[0];
        for(int num: nums) {
            if(num == candiA) {
                ++A; continue;
            }else if(num == candiB) {
                ++B; continue;
            }

            if(A == 0) {
                candiA = num;
                ++A; continue;
            }

            if(B == 0) {
                candiB = num;
                ++B; continue;
            }

            --A; --B;
        }

        A = 0; B = 0;
        for(int num: nums) {
            if(num == candiA) 
                ++A;
            if(num == candiB) 
                ++B;
        }
        if(candiA == candiB) {
            res.push_back(candiA);
            return res;
        }
        if(A>len/3) res.push_back(candiA);
        if(B>len/3) res.push_back(candiB);
        return res;
    }
};

int main() {}