#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
private:
    int front, rear, size;
    int *arr;

public:
    MyQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }
    void enqueue(int value)
    {
        if ((rear + 1) % size == front)
        {
            cout << "Queue is empty\n";
            return;
        }
        if (front == -1)
        {
            front = rear = 0;
            arr[rear] = value;
            return;
        }
        rear++;
        rear %= size;
        arr[rear] = value;
    }
    void dequeue()
    {
        if (front == rear)
        {
            front = rear = -1;
            return;
        }
        front = (front + 1) % size;
    }
    void show()
    {
        int i = front;
        for (; i != rear; i %= size)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i++;
        }
        if (i == rear)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    MyQueue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.show();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.show();
    q.enqueue(3);
    q.enqueue(1);
    q.enqueue(2);
    q.show();
    return 0;
}