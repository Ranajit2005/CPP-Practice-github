#include<iostream>
using namespace std;

class Crq{
    int front;
    int rear;
    int *Q;
    int size;
public:
    Crq(int s){
        size = s;
        front = 0;
        rear = 0;
        Q = new int[size];
    }

    bool isFull(){
        if(front == (rear + 1)%size){
            cout<<"Full"<<endl;
            return 1;
        }
        return 0;
    }

    bool isEmpty(){
        if(front == rear){
            cout<<"empty"<<endl;
            return 1;
        }
        return 0;
    }

    void Display(){
        int i = front + 1;
        do{
            cout<<Q[i]<<" ";
            // i++;
            i = (i + 1) % size;
        }while(i!=(rear +1)%size);
        cout<<endl;
    }

    void EnQ(int x){
        if (isFull()){
        cout << "Queue overflow" << endl;
        return;
        }
        rear = (rear +1)%size;
        Q[rear] = x;
    }

    int DeQ(){
        if (isEmpty()){
        cout << "Queue is underflow" << endl;
        return -1;
        }
        front = (front + 1)%size;
        int x = Q[front];
        return x;
    }
};

int main(){
    Crq q(5);
    q.EnQ(10);
    q.EnQ(20);
    q.EnQ(30);
    q.EnQ(40);
    // q.EnQ(10);
    q.Display();
    cout<<endl;
    cout<<q.DeQ()<<endl;
    q.Display();


    return 0;
}