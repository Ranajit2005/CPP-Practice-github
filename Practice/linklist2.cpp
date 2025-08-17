#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int value){
        data=value;
        next=NULL;
    }
};

Node *InsertAtFirst(Node *head,int value){
    Node *ptr = new Node(value);
    ptr->next=head;
    return ptr;
}

Node *InsertAtEnd(Node *head,int value){
    Node *ptr = new Node(value);
    Node *temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=ptr;
    ptr->next=NULL;
    return head;
}

Node *InsertAtBetween(Node *head,int value,int index){
    Node *ptr = new Node(value);
    Node *p = head; // head is pointer , so it has not value 0  
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

void display(Node *head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        // cout<<temp->next<<endl;
        temp=temp->next;
    }
}

int main(){
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    
    head->next = second;
    second->next=third;
    third->next=fourth;
    fourth->next=NULL;
    display(head);
    // head = InsertAtFirst(head,6);
    cout<<"Now Linklist is: "<<endl;
    // head = InsertAtEnd(head,7);
    head = InsertAtBetween(head,10,2);
    display(head);
return 0;
}