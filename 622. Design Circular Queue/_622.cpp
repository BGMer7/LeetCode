#include <vector>
#include <iostream>

class MyCircularQueue
{
private:
    int cap;
    int front;
    int rear;
    int *data;
    int used;

public:
    MyCircularQueue(int k)
    {
        cap = k;
        data = new int[k];
        front = 0;
        rear = 0;
        used = 0;
    }

    ~MyCircularQueue()
    {
        delete[] data;
        data = nullptr;
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;

        data[rear] = value;
        ++rear;
        if (rear == cap)
            rear = 0;
        ++used;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;

        if (front == cap - 1)
            front = 0;
        else
            ++front;
        --used;
        return true;
    }

    int Front()
    {
        return isEmpty() ? -1 : data[front];
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        else if (rear == 0)
            return data[cap - 1];
        else
            return data[rear - 1];
    }

    bool isEmpty()
    {
        return used == 0;
    }

    bool isFull()
    {
        return used == cap;
    }
};


int main()
{
    int a[3];
    int *ap = a;
    std::cout << &ap << std::endl;
    *(ap++) = 1;
    *(ap++) = 2;
    *(ap++) = 3;
    std::cout << &a[2] << std::endl;

    int *data[3];
    std::cout << &data << std::endl;
}