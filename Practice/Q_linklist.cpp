#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value){
        data=value;
        next=NULL;
    }
};

class Q
{
    Node *front;
    Node *rear;

public:
    Q(){
        front = NULL;
        rear = NULL;
    }
    void enqueue(int );
    void dequeue();
    void display();
    bool isEmpty();

};

void Q :: enqueue(int value){
    Node *ptr = new Node(value);
    if (ptr == NULL) cout<<"Overflow"<<endl; //heap is full
    ptr->next = NULL;
    if(front == NULL){ // for single node insert
        front = ptr;
        rear = ptr;
    }else{
        rear->next = ptr;
        rear = ptr;
    }
}

bool Q :: isEmpty(){
    if(front == NULL) return 1;
    else return 0;
}

void Q :: dequeue(){
    Node *temp;
    if(isEmpty()) cout<<"Under flow "<<endl;
    temp = front;
    front = front->next;
    delete temp;

}

void Q :: display(){
    Node *p = front;
    while(p){
        cout<< p->data <<" ";
        p = p->next;
    }
    cout<<endl;
}

int main()
{
    Q q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    q.enqueue(6);
    q.enqueue(7);
    q.display();
    return 0;
}