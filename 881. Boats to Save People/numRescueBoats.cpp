#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        const int num = people.size();
        int left = 0, right = num-1, res = 0;
        while(left<=right) {
            int weight = 0;
            if(people[left]+people[right]>limit) 
                --right;
            else {
                --right;++left;
            }
            
            ++res;
        }
        return res;
    }
};

int main() {}