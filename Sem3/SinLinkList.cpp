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
            t->next = head;
            head = t;  
    }

    void InsertLast(int x){
        Node* p = head;
        Node* t = new Node(x);
        while(p->next!=NULL){
            p=p->next;
        }
        p->next = t;
    }

    void InsertPos(int x,int pos){
        Node* p = head;
        Node *t = new Node(x);
        for(int i=1;i<pos - 1 && p;i++){
            p=p->next;
        }
        t->next = p->next;
        p->next = t;
    }

    void Display(){
        Node *p = head;
        while(p){
            cout<<p->data<<" ";
            p=p->next;
        }
    }
};

int main(){
    Linklist li;
    li.InsertFirst(10);
    li.InsertFirst(20);
    li.InsertFirst(30);
    // li.InsertFirst(40);
    // li.InsertFirst(50);

    li.Display();
    cout<<endl;

    li.InsertLast(15);
    li.InsertLast(25);
    li.Display();
    cout<<endl;

    li.InsertPos(17,3);
    li.Display();
    cout<<endl;
    li.InsertPos(33,5);

    li.Display();
    cout<<endl<<"End";
    return 0;
}