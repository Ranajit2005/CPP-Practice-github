#include <iostream>
using namespace std;

class Node{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue{
private:
    int size;
    int front;
    int rear;
    Node **Q;

public:
    Queue(int size);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void enqueue(Node *x);
    Node *dequeue();
};

Queue::Queue(int size){
    this->size = size;
    front = -1;
    rear = -1;
    Q = new Node *[size];
}

Queue::~Queue(){
    delete[] Q;
}

bool Queue::isEmpty(){
    if (front == rear)
    {
        return true;
    }
    return false;
}

bool Queue::isFull(){
    if (rear == size - 1)
    {
        return true;
    }
    return false;
}

void Queue::enqueue(Node *x){
    if (isFull())
    {
        cout << "Queue Overflow" << endl;
    }
    else
    {
        rear++;
        Q[rear] = x;
    }
}

Node *Queue::dequeue(){
    Node *x = NULL;
    if (isEmpty())
    {
        cout << "Queue Underflow" << endl;
    }
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}

class tree{
public:
    Node *root;
    tree()
    {
        root = NULL;
    }
    Node *getRoot()
    {
        return root;
    }
    void createTree();
    void preorder(Node *);
    void postorder(Node *);
    void inorder(Node *);
};

void tree ::createTree(){
    Queue q(25);    // it also difine in input type
    Node *t;
    root = new Node;
    int x;
    cout << "Enter the value of root : ";
    cin >> x;
    root->data = x;
    root->lchild = NULL;
    root->rchild = NULL;
    q.enqueue(root);
    while (!q.isEmpty())
    {
        Node *p;
        p = q.dequeue();
        cout << "Enter left child value of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            q.enqueue(t);
        }

        cout << "Enter right child value of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void tree ::preorder(Node *p){

    if (p != NULL)
    {
        cout << p->data << ", ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
    // cout << endl;
}

void tree ::postorder(Node *p){
    if (p != NULL)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data << ", ";
    }
    // cout << endl;
}

void tree ::inorder(Node *p){

    if (p != NULL)
    {
        inorder(p->lchild);
        cout << p->data << ", ";
        inorder(p->rchild);
    }
    // cout << endl;
}

int main(){
    tree t;
    t.createTree();

    cout << "Preorder is : ";
    t.preorder(t.getRoot());
    cout << endl;

    cout << "Postorder is : ";
    t.postorder(t.getRoot());
    cout << endl;

    cout << "Inoder is : ";
    t.inorder(t.getRoot());
    cout << endl;

    return 0;
}