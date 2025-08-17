#include<iostream>
using namespace std;

class Linklist{
    int rear = -1;
    int front = -1;
    // int size;
public:
    struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
    } *head;
    // Node* head;

    Linklist(){head = NULL;}

    void InsertLast(int x){
        Node* t = new Node(x);
        if(head == NULL){
            head = t;
            return;
        }
        Node* p = head;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next = t;
    }

    void Display(){
        Node *p = head;
        while(p){
            cout<<p->data<<" ";
            p=p->next;
        }
    }
 
    int DeleteFirst(){
        if(head == NULL){
            cout<<"LInklistt is Empty ";
            return -1;
        }    
        Node* t = head;
        head = head->next;
        int x = t->data;
        delete t;
        return x;
    }
        // bool isFull(){
        // if(rear == size - 1){
        //     cout<<"Queue is Full "<<endl;
        //     return 1;
        // }
        // return 0;
    // }

    bool isEmpty(){
        if(front == rear){
            cout<<"Queue is empty"<<endl;
            return 1;
        }
        return 0;
    }

    void enQ(int x){
        // if(isFull()){
        //     cout<<"Overflow "<<endl;
        //     return;
        // }
        rear++;
        InsertLast(x);
    }

    int deQ(){
        if(isEmpty()){
            cout<<"Under flow";
            return -1;
        }
        front++;
        int x = DeleteFirst();
        return x;
    }
};

int main(){
    Linklist li;
    li.enQ(20);
    li.enQ(10);
    li.enQ(30);

    li.Display();
    li.deQ();
    cout<<endl;
    li.Display();
    cout<<endl<<"End";
    return 0;
}
