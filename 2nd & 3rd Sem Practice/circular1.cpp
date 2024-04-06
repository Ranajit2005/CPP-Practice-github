#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

// class Node
// {
//     public:
//     int data;
//     Node *next;

// Node(int value){
//     data = value;
//     next = NULL;
// }

// };

void display(Node *head){
    Node *ptr = head;
    do
    {
        cout << "Element : " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != head);
}

Node *insertFirst(int value, Node *head){
    Node *p = head->next;
    Node *ptr = new Node(value);
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

Node *InsertAtBetween(Node *head, int value, int index){
    Node *ptr = new Node(value);
    Node *p = head; // head is pointer , so it has not value 0
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

int main(){
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = head;

    display(head);
    // cout<<"After insert at first"<<endl;
    // head = insertFirst(5, head);
    cout << "Insert at between " << endl;
    head = InsertAtBetween(head, 6, 2);
    display(head);
    return 0;
}