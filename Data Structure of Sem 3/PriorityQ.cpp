#include<iostream>
using namespace std;

class PriorityQueue
{
    struct Node
    {
        int data, priority;
        Node *next;
        Node(int value, int prio)
        {
            data = value;
            priority = prio;
            next = NULL;
        }
    } *head;

public:
    PriorityQueue()
    {
        head = NULL;
    }
    void insert(int value, int prio)
    {
        Node *newNode = new Node(value, prio);
        if (head == NULL)
        {
            head = newNode;
        }
        else if (head->priority < prio)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next && temp->next->priority >= prio)
                temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    int erase()
    {
        if (!head)
        {
            cout << "Empty." << endl;
            return -1;
        }
        int value = head->data;
        Node *temp = head;
        head = head->next;
        delete temp;
        return value;
    }
    void display()
    {
        if (head == NULL)
        {
            cout << "Empty." << endl;
            return;
        }
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " " << temp->priority << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    PriorityQueue q;
    while (1)
    {
        int value;
        cin >> value;
        if (value == 1)
        {
            cout << "Enter data and prio\n";
            int data, p;
            cin >> data >> p;
            q.insert(data, p);
        }
        else
        {
            cout << q.erase() << endl;
        }
        q.display();
    }
    return 0;
}