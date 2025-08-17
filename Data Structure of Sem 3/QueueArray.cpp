#include<iostream>
using namespace std;

class Q{
    int front;
    int rear;
    int size;
    int *Qu;
public:
    Q(int s){
        size = s;
        front = -1;
        rear = -1;
        Qu = new int[size];
    }
    bool isFull(){
        if(rear == size - 1){
            cout<<"Queue is Full "<<endl;
            return 1;
        }
        return 0;
    }

    bool isEmpty(){
        if(front == rear){
            cout<<"Queue is empty"<<endl;
            return 1;
        }
        return 0;
    }

    void enQ(int x){
        if(isFull()){
            cout<<"Overflow "<<endl;
            return;
        }
        rear++;
        Qu[rear] = x;
    }

    int deQ(){
        if(isEmpty()){
            cout<<"Under flow";
            return -1;
        }
        front++;
        int x = Qu[front];
        return x;
    }

    void Display(){
        for(int i = front + 1;i<=rear;i++){
            cout<<Qu[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Q qu(5);
    qu.enQ(10);
    qu.enQ(20);
    qu.enQ(30);
    qu.enQ(40);
    qu.enQ(50);
    // qu.enQ(50);
    qu.Display();
    qu.deQ();
    qu.Display();
    return 0;
}