#include<iostream>
using namespace std;

class CircularLinkList{
public:
    struct Node{
        int data;
        Node* next;
        Node(int x){
            data = x;
            next = NULL;
        }
    } *head;

    CircularLinkList(){
        head = NULL;
    }
    void InsertAtFirst(int x){
        Node* t = new Node(x);
        if(head == NULL){
            head = t;
            t->next = head;
        }
        // Node* last = head;
        Node* p = head;
        while (p->next!=head){
            p = p->next;
        }
        t->next = head;
        p->next = t;
        head = t;
    }

    void InsertPos(int x,int pos){
        Node* t = new Node(x);
        Node* p = head;
        for(int i = 1;i<pos - 1;i++){
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }

    void Display(){
        Node* p = head;
        do{
            cout<<p->data<<" ";
            p = p->next;
        }while (p!=head); 
    }

};

int main(){
    CircularLinkList cr;
    cr.InsertAtFirst(10);
    cr.InsertAtFirst(20);
    cr.InsertAtFirst(30);
    cr.InsertAtFirst(40);
    cr.InsertAtFirst(50);
    cr.Display();
    cout<<endl;
    cr.InsertPos(15,3);

    cr.Display();

    return 0;
}