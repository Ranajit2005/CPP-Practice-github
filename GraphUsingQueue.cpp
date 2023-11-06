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
        rear ++;
        arr[rear] = data;
    }
    return;
}

void Q :: DeQ(){
    if(!isEmpty()){
        front++;
    }
    return;
}

void Q :: display(){
    for (int i = front + 1; i <= rear; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    Q rd(5);
    rd.EnQ(1);
    rd.EnQ(2);
    rd.EnQ(3);
    rd.EnQ(4);
    rd.EnQ(5);
    rd.display();
    
    return 0;
}