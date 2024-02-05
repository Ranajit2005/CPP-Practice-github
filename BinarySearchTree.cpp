#include <iostream>
using namespace std;

class Node{
public:
    Node *lchild;
    int data;
    Node *rchild;
    Node(int value){
        data = value;
    }
};

class BST{
    Node *root;
public:
    Node* getroot(){
        return root;
    }
    BST() { root = nullptr; }
    void Insert(int);
    void Inorder(Node *);
    int CountNode(Node* );
    int CountLeafNode(Node* );
    int Hight(Node* );
    bool search(int);
    Node* Delete(Node* ,int);
    Node* InorderPredissor(Node* );
    Node* InorderSuccesor(Node* );
    Node* setroot(Node* temp){
        root = temp;
    }
};

void BST ::Insert(int key){
    Node *t = root;
    Node *p = new Node(key);
    Node *r;
    if (root == nullptr){
        // p = new Node(key);
        p->lchild = nullptr;
        p->rchild = nullptr;
        root = p;
        return;
    }
    while (t != nullptr){
        r = t;
        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        else
            return;
    }
    p->lchild = nullptr;
    p->rchild = nullptr;
    if (key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}

void BST ::Inorder(Node *p){
    if (p){
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

bool BST :: search(int x){
    Node* t = root;
    while(t!=nullptr){
        if(x == t->data){
            return 1;
        }    
        else if(x<t->data){
            t=t->lchild;
        }
        else {
        t = t->rchild;
        }
    }
    return 0;
}

int BST :: CountNode(Node* p){
    int x=0,y=0;
    if(p!=nullptr){
        x=CountNode(p->lchild);
        y=CountNode(p->rchild);
        return x+y+1;
    }
    return 0;
}

int BST :: CountLeafNode(Node* p){  //not working
    int x=0,y=0;
    if(p){
        x=CountLeafNode(p->lchild);
        y=CountLeafNode(p->rchild);
        if(p->lchild==NULL && p->rchild==NULL){
        return x+y+1;
        }
        return x+y;
    }
    return 0;
}

int BST :: Hight(Node* r){
    int lefthight,righthight;
    if(r == nullptr) return 0;
    else{
        lefthight = Hight(r->lchild);
        righthight = Hight(r->rchild);
        if(lefthight > righthight)  return (lefthight + 1);
        else    return (righthight+1);
    }
}

Node* BST :: InorderPredissor(Node* p){
    p = p->lchild;
    while(p->rchild){
        p = p->rchild;
    }
    return p;
}

Node* BST :: InorderSuccesor(Node* p){
    p = p->rchild;
    while(p->lchild){
        p = p->lchild;
    }
    return p;
}

Node* BST :: Delete(Node* p, int key){      //recursively delete
    //Base case
    if(p == nullptr)    return NULL;
    if(p->lchild ==nullptr && p->rchild == nullptr && p->data == key){
        if(p == root)   root = nullptr;
        delete p;
        return nullptr;
    }

    //Searching key
    Node* temp;
    if(key > p->data)   p->rchild = Delete(p->rchild , key);
    else if(key < p->data)  p->lchild = Delete(p->lchild , key);
    else{
        if(Hight(p->lchild) > Hight(p->rchild)){
            temp = InorderPredissor(p);
            p->data = temp->data;
            p->lchild = Delete(p->lchild, p->data);
        }    
        else{
            temp = InorderSuccesor(p);
            p->data = temp->data;
            p->rchild = Delete(p->rchild,p->data);
        }
    }
    return p;
}

int main(){
    BST rd;
    rd.Insert(30);
    rd.Insert(50);
    rd.Insert(10);
    rd.Insert(60);
    rd.Insert(20);
    rd.Insert(70);

    // // Insert using loop
    // cout<<"Insert the element and press -1 for stop insertion : ";
    // for(int i=0;;i++){
    //     int x;
    //     cin>>x;
    //     if(x==-1)   break;
    //     rd.Insert(x);
    // }

    cout<<"The inorder is : ";
    rd.Inorder(rd.getroot());

    // int x;
    // cout<<endl<<"Which number you want to search : "; 
    // cin>>x;
    // if(rd.search(x))   cout<<"Found "<<endl;
    // else    cout<<"Not Found "<<endl;
    
    // cout<<"The number of Nodes are "<<rd.CountNode(rd.getroot())<<endl;
    // cout<<"The number of leaf Nodes are "<<rd.CountLeafNode(rd.getroot())<<endl;  //not working
    // cout<<"The hight is : "<<rd.Hight(rd.getroot())<<endl;

    int y;
    cout<<endl<<"Which number you want to delete : "; 
    cin>>y;
    rd.setroot(rd.Delete(rd.getroot(),y));
    cout<<"After delete the Inorder is : ";
    rd.Inorder(rd.getroot());
    return 0;
}