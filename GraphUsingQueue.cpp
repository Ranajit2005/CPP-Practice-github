#include<iostream>
using namespace std;

class Q{
    int size;
    int front;
    int rear;
    int *arr;
public:
    Q(int s){
        size = s;
        front = rear = -1;
        arr = new int[size];
    }
    bool isFull();
    bool isEmpty();
    void EnQ(int );
    void DeQ();
    void display();
};

bool Q :: isFull(){
    if(rear == size-1){
        cout<<"Queue is full";
        return 1;
    }   
    return 0;
}

bool Q :: isEmpty(){
    if(rear == front){
        cout<<"Queue is empty";
        return 1;
    }
    return 0;
}

void Q :: EnQ(int data){
    if(!isFull()){

    }
}