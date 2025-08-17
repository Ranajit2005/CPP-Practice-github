#include<iostream>
using namespace std;

class Linklist{
    int top = -1;
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

    void push(int x){
        top++;
        InsertFirst(x);
    }

    int pop(){
        int a;
        a = DeleteFirst();
        top--;
        return a;
    }

};



int main(){
    Linklist li;
    li.push(1);
    li.push(2);
    li.push(3);
    li.push(4);
    li.Display();
    cout<<endl<<"Pop element is : "<<li.pop()<<endl;
    li.Display();
    
    cout<<endl<<"End";
    return 0;
}