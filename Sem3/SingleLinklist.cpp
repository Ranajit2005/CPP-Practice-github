#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

class Linklist{
public:
    Node* head;
    Linklist(){head = NULL;}
    void InsertFiert(int x,Node* head){
        Node* t = new Node(x);
        if(head == NULL){
            head = t;
        }
        t->next = head;
        head = t;
    }

    void Display(Node* p){
        while(p->next!=NULL){
            cout<<p->data<<" ";
            p=p->next;
        }
    }
};

int mian(){
    Linklist li;
    li.InsertFiert(10,);
    return 0;
}