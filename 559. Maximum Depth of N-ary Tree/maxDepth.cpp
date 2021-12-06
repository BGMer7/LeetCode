#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class SolutionDFS
{
public:
    int maxDepth(Node *root)
    {
        if (!root)
            return 0;
        int depth = 0;
        vector<Node *> children = root->children;

        for (auto child : children)
        {
            int childDepth = maxDepth(child);
            depth = max(depth, childDepth);
        }
        return depth + 1;
    }
};

class SolutionBFS
{
public:
    int maxDepth(Node *root)
    {
        if (!root)
            return 0;

        int depth = 0;
        queue<Node *> q;
        queue.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i; i < size; ++i)
            {
                Node *n = q.front();
                if (n->children)
                    q.push(n->children);
                q.pop();
            }
            ++depth;
        }
    }
};

int main() {}