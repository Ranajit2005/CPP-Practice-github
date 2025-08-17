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

void display(Node *head){
    Node* ptr = head;
    while(ptr!=NULL){
        cout<<"Element : "<<ptr->data<<endl;
        ptr=ptr->next;
    }
}

Node* DeleteAtFirst(Node* head){
    Node* ptr = head;
    head=head->next;
    delete ptr;
    // free(ptr);
    return head;
}

Node* DeleteAtEnd(Node* head){
    Node* p = head;
    Node* ptr = head->next;
    while(ptr->next!=NULL){
        p=p->next;
        ptr=ptr->next;
    }
    p->next=NULL;
    delete ptr;
    return head;
}

Node* DeleteAtBetween(Node* head,int index){
    Node* p = head;
    Node *ptr = head->next;
    int i = 0;
    while(i!=index-1){
        p = p->next;
        ptr = ptr->next;
        i++;
    }
    p->next=ptr->next;
    delete ptr;
    return head;
}

Node* DeleteGivenValue(Node* head,int value){
    Node* p = head;
    Node* q = head->next;
    while(q->data!=value && q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    if(q->data==value){
        p->next = q->next;
    }
    delete q;
    return head;
}

int main(){
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fouth = new Node(4);
    Node *fifth = new Node(5);

    head->next=second;
    second->next=third;
    third->next=fouth;
    fouth->next=fifth;
    fifth->next=NULL;

    display(head);
    cout<<"After delete : "<<endl;

    // head=DeleteAtFirst(head);
    // head = DeleteAtEnd(head);
    // head = DeleteAtBetween(head,3);
    head = DeleteGivenValue(head,4);
    display(head);
return 0;
}