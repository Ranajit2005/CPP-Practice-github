#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

void display(Node *head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

int main(){

    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;

    head->data = 1;
    head->next = second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=fourth;

    fourth->data=5;
    fourth->next=NULL;

    display(head);

return 0;
}