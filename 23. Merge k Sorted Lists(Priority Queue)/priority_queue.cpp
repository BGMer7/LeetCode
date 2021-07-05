#include <vector>
#include <iostream>
#include "print.h"
#include <queue>

using namespace std;

class PriorityQueue
{
private:
    vector<int> priority_queue;

public:
    void swim(int pos)
    {
        while (pos > 1 && priority_queue[pos] > priority_queue[pos / 2])
        //通常来说，优先队列的vector的index是从1开始的，而不是从0开始，vector[0]就空着
    }

    void push(int x)
    {
        priority_queue.push_back(x);
    }
};


main()
{
    vector<int> v{23, 34, 6, 16, 325, 234, 37, 33, 17, 30, 36, 7, 3, 7, 56, 84, 32, 24};
    //Heap heap;
    //heap.heapAdjust(v);
    Print p;
    p.printVector(v);
    PHeap ph;
    ph.push(12);
    ph.push(32);
    ph.push(34);
    ph.push(38);
    ph.push(23);

}