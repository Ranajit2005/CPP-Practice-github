#include<iostream>
using namespace std;

class Linklist{
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
    void InsertFirst(int x){
        Node* t = new Node(x);
        if(head == NULL){
            head = t;
        }else{
            t->next = head;
            head = t;
        }
        
    }

    void Display(){
        Node *p = head;
        while(p){
            cout<<p->data<<" ";
            p=p->next;
        }
    }
};

int mian(){
    Linklist li;
    li.InsertFirst(20);
    // li.InsertFirst(30);
    // li.InsertFirst(40);
    // li.InsertFirst(50);
    // li.InsertFirst(10);

    li.Display();
    cout<<"End";
    return 0;
}