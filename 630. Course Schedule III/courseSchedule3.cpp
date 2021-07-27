#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


class Solution
{
public:
    int scheduleCourse(vector<vector<int>> &courses)
    {
        priority_queue<int> pq;
        sort(courses.begin(), courses.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1]<b[1];
        });

        int n = courses.size();
        int date = 0;
        for(int i(0); i<n; ++i) {
            if(date+courses[i][0]<=courses[i][1]) {
                date += courses[i][0];
                pq.push(courses[i][0]);
            } else {
                if(!pq.empty() && courses[i][0]<pq.top()) {
                    date = date-pq.top()+courses[i][0];
                    pq.pop();
                    pq.push(courses[i][0]);
                }
            }
        }
        return pq.size();
    }
};

int main() {}