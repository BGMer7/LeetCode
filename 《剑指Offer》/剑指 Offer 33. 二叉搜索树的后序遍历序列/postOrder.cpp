#include <vector>
using namespace std;

class Solution
{
public:
    bool verifyPostorder(vector<int> &postorder)
    {
        return dfs(0, postorder.size()-1, postorder);
    }

    bool dfs(int left, int right, vector<int> &postorder)
    {
        if (left >= right)
            return true;
        int root = postorder[right];
        int index = left;
        while (index < right && postorder[index] < root)
            ++index;

        for (int i(index); i < right; ++i)
            if (postorder[i] < root)
                return false;

        return dfs(left, index-1, postorder) && dfs(index, right-1, postorder);
    }
};

int main(){}