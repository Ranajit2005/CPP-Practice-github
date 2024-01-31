#include<iostream>
using namespace std;

struct Node
{
    int coeff, expo;
    Node *next;
    Node(int coeff, int expo)
    {
        this->coeff = coeff;
        this->expo = expo;
        next = NULL;
    }
};

Node *insert(Node *head, int co, int ex)
{
    if (co == 0)
        return head;
    if (head == nullptr)
        return new Node(co, ex);
Node *temp = head, *prev = NULL;
    while (temp && temp->expo > ex)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp && temp->expo == ex)
    {
        temp->coeff += co;
    }
    else
    {
        Node *newNode = new Node(co, ex);
        newNode->next = temp;
        if (prev == NULL)
        {
            head = newNode;
        }
        else
        {
            prev->next = newNode;
        }
    }

    return head;
}
void display(Node *head)
{
    while (head)
    {
        cout << head->coeff << "X^" << head->expo << " -> ";
        head = head->next;
    }
}

int main()
{
    // CircularQueue<int> q;
    Node *head = NULL;
    while (5)
    {
        int c, e;
        cin >> c >> e;
        head = insert(head, c, e);
        display(head);
    }
    return 0;
}