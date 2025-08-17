#include <iostream>
using namespace std;

class CircularQueue
{
    int size;
    int front;
    int rear;
    int *Q;

public:
    CircularQueue(int size);
    bool isFull();
    bool isEmpty();
    void enQ(int data);
    void deQ();
    void display();
};

CircularQueue ::CircularQueue(int s)
{
    this->size = s;
    front = 0;
    rear = 0;
    Q = new int[size];
}

bool CircularQueue ::isFull()
{
    if ((rear + 1) % size == front)
    {
        cout << "The Queue is full" << endl;
        return 1;
    }
    return 0;
}

bool CircularQueue ::isEmpty()
{
    if (rear == front)
    {
        cout << "Queue is empty" << endl;
        return 1;
    }
    return 0;
}

void CircularQueue ::enQ(int a)
{
    if (isFull())
    {
        cout << "Queue overflow" << endl;
        return;
    }
    rear = (rear + 1) % size;
    Q[rear] = a;
}

void CircularQueue ::deQ()
{
    if (isEmpty())
    {
        cout << "Queue is underflow" << endl;
        return;
    }
    front = (front + 1) % size;
    // int x = Q[front];
    // delete x;
}

void CircularQueue ::display()
{
    int i = front + 1;
    do {
        cout << Q[i]<<" ";
        i = (i + 1) % size;
        // i++;
    } while (i != (rear + 1) % size);
    cout << endl;
}

int main()
{
    CircularQueue Q(10);
    Q.enQ(1);
    Q.enQ(2);
    Q.enQ(3);
    Q.enQ(4);
    Q.display();
    Q.enQ(5);
    Q.display();
    Q.enQ(6);
    Q.deQ();
    Q.display();
    Q.enQ(7);
    Q.display();
    return 0;
}
