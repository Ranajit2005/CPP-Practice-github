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
    bool isFull(Q *q);
    bool isEmpty(Q *q);
    void EnQ(Q *q,int );
    int DeQ(Q *q);
    void display(Q *q);
};

bool Q :: isFull(Q *q){
    if(q->rear == q->size-1){
        cout<<"Queue is full";
        return 1;
    }   
    return 0;
}

bool Q :: isEmpty(Q *q){
    if(q->rear == q->front){
        cout<<"Queue is empty";
        return 1;
    }
    return 0;
}

void Q :: EnQ(Q *q,int data){
    if(!isFull(q)){
        q->rear ++;
        arr[q->rear] = data;
    }
    return;
}

int Q :: DeQ(Q *q){
    if(!isEmpty(q)){
        q->front++;
        int x = arr[q->front];
        return x;
    }
    return -1;
}

void Q :: display(Q *q){
    for (int i = q->front + 1; i <= q->rear; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    Q rd(5);
    rd.EnQ(&rd,1);
    rd.EnQ(&rd,2);
    rd.EnQ(&rd,3);
    rd.EnQ(&rd,4);
    rd.EnQ(&rd,5);
    rd.display(&rd);
    rd.DeQ(&rd);
    rd.display(&rd);
    return 0;
}