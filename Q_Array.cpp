#include <iostream>
using namespace std;

class Queue
{
    int size;
    int front;
    int rear;
    int *Q;

public:
    Queue(int size);
    bool isFull();
    bool isEmpty();
    void enQ(int data);
    void deQ();
    void display();
};

Queue ::Queue(int s)
{
    this->size = s;
    front = -1;
    rear = -1;
    Q = new int[size];  // remember this line
}

bool Queue ::isEmpty()
{
    if (rear == front)
    {
        cout << "The Queue is empty" << endl;
        return 1;
    }
    return 0;
}

bool Queue ::isFull()
{
    if (rear == size - 1)
    {
        cout << "Queue is full" << endl;
        return 1;
    }
    return 0;
}

void Queue ::enQ(int a)
{
    if (isFull())
    {
        cout << "Queue overflow" << endl;
        return;
    }
    rear++;
    Q[rear] = a;
}

void Queue ::deQ()
{
    if (isEmpty())
    {
        cout << "Queue is underflow" << endl;
        return;
    }
    front++;
    int x = Q[front];
    // delete x;
}

void Queue ::display()
{
    for (int i = front + 1; i <= rear; i++)
    {
        cout << Q[i] << " ";
    }
    cout << endl;
}

int main()
{
    Queue Q(5);
    Q.enQ(1);
    Q.enQ(2);
    Q.enQ(3);
    Q.enQ(4);
    Q.enQ(5);
    Q.display();
    Q.enQ(6);
    Q.deQ();
    Q.display();
    Q.enQ(7);

    return 0;
}
