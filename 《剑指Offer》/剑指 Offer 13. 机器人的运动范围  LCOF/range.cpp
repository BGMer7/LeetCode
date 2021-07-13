#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int res;
    bool visited[100][100];
public:
    int movingCount(int m, int n, int k) {
        dfs(m, n, 0, 0, k);  
        return res;
    }
    void dfs(int m, int n, int i, int j, int k) {
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j]) return ;
        if(i % 10 + j % 10 + i / 10 + j / 10 > k)   return ;
        visited[i][j] = true;
        ++res;
        dfs(m, n, i + 1, j, k), dfs(m, n, i, j + 1, k), dfs(m, n, i - 1, j, k), dfs(m, n, i, j - 1, k);
    }
};

int main() {}