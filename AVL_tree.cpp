#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* lchild;
    Node* rchild;
    int hight;
    Node(int value){
        data = value;
        lchild=rchild=nullptr;
    }
};

class AVL{
    Node* root;
public:
    AVL(){
        root = nullptr;
    }
    Node* getroot(){
        return root;
    }
    Node* setroot(Node* temp){
        root=temp;
    }
    int getHight(Node* );
    int BalanceFac(Node* );
    Node* Insert(Node* ,int);
    Node* LLRotation(Node* );
    Node* RRRotation(Node* );
    Node* LRRotation(Node* );
    Node* RLRotation(Node* );
    void Inorder(Node* );
    void Preorder(Node* );
    Node* Delete(Node*, int);
    Node* InorderPredissor(Node*);
    Node* InorderSuccesor(Node* );
};

int AVL::getHight(Node* p){
    if(p==nullptr)  return 0;
    return p->hight;
}

int AVL::BalanceFac(Node* p){
    if(p==nullptr)  return 0;
    return getHight(p->lchild) - getHight(p->rchild);
    // return p->lchild->hight - p->rchild->hight;
}

void AVL::Inorder(Node* p){
    if(p){
        Inorder(p->lchild);
        cout<<p->data<<", ";
        Inorder(p->rchild);
    }
}

void AVL ::Preorder(Node *p){
    if (p){
        cout << p->data << ", ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

Node* AVL::LLRotation(Node* p){
    Node* pl = p->lchild;
    Node* plr = pl->rchild;

    // operation Perform
    pl->rchild = p;
    p->lchild = plr;

    //update hight whose hight are change
    p->hight = max(getHight(p->lchild),getHight(p->rchild))+1;
    pl->hight = max(getHight(pl->lchild),getHight(pl->rchild))+1;

    //update root(if root is changed)
    if(p==root) root == pl;
    return pl;
}

Node* AVL::LRRotation(Node* p){
    Node* pl = p->lchild;
    Node* plr = pl->rchild;

    //operation perform
    plr->rchild = p;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    pl->rchild = plr->lchild;

    //update hight whose hight are change
    p->hight = max(getHight(p->lchild),getHight(p->rchild))+1;
    pl->hight = max(getHight(pl->lchild),getHight(pl->rchild))+1;

    //update root(if root is changed)
    if(p==root) root == plr;
    return plr;
}

Node* AVL::RRRotation(Node* p){
    Node* pr = p->rchild;
    Node* prl = pr->lchild;

    //operation perform
    pr->lchild = p;
    p->rchild = prl;

    //update hight whose hight are change
    p->hight = max(getHight(p->lchild),getHight(p->rchild))+1;
    pr->hight = max(getHight(pr->lchild),getHight(pr->rchild))+1;

    //update root(if root is changed)
    if(p==root) root == pr;
    return pr;
}

Node* AVL::RLRotation(Node* p){
    Node* pr = p->rchild;
    Node* prl = pr->lchild;

    //operation perform
    prl->lchild = p;
    p->rchild = prl->lchild;
    prl->rchild = pr;
    pr->lchild = prl->rchild;

    //update hight whose hight are change
    p->hight = max(getHight(p->lchild),getHight(p->rchild))+1;
    pr->hight = max(getHight(pr->lchild),getHight(pr->rchild))+1;

    //update root(if root is changed)
    if(p==root) root == prl;
    return prl;
}

Node* AVL::Insert(Node* p,int key){     //recursive insert
    // if(root==nullptr){
    //     Node* temp = new Node(key);
    //     temp->hight = 1;
    //     root = temp;
    //     return root;
    // }
    if(p==nullptr){
        Node* t = new Node(key);
        t->hight = 1;
        return t;
    }
    if(key < p->data)   p->lchild=Insert(p->lchild,key);
    else if(key > p->data)  p->rchild=Insert(p->rchild,key);

    //update hight 
    p->hight = max(getHight(p->lchild),getHight(p->rchild)) + 1;
    
    //perform rotation
    if(BalanceFac(p)==2 && BalanceFac(p->lchild)==1)    p=LLRotation(p);
    if(BalanceFac(p)==-2 && BalanceFac(p->rchild)==-1)    p=RRRotation(p);
    if(BalanceFac(p)==2 && BalanceFac(p->lchild)==-1)    p=LRRotation(p);
    if(BalanceFac(p)==-2 && BalanceFac(p->rchild)==1)    p=RLRotation(p);

    return p;
}

Node* AVL :: InorderPredissor(Node* p){
    p = p->lchild;
    while(p->rchild){
        p = p->rchild;
    }
    return p;
}

Node* AVL :: InorderSuccesor(Node* p){
    p = p->rchild;
    while(p->lchild){
        p = p->lchild;
    }
    return p;
}

Node* AVL :: Delete(Node* p,int key){
    if(p == nullptr)    return nullptr;
    if(p->lchild == nullptr && p->rchild == nullptr && p->data == key){
        if(p==root) root = p;
        delete p;
        return nullptr;
    }
    Node* temp;
    if(key < p->data) p->lchild = Delete(p->lchild,key);
    else if(key > p->data) p->rchild = Delete(p->rchild,key);
    else{
        if(p->lchild->hight>p->rchild->hight){
            temp = InorderPredissor(p);
            p->data = temp->data;
            p->lchild = Delete(p->lchild, p->data);
        }else{
            temp = InorderSuccesor(p);
            p->data = temp->data;
            p->rchild = Delete(p->rchild, p->data);
        }
    }
    p->hight = max(getHight(p->lchild),getHight(p->rchild))+1;

    //perform roration
    if(BalanceFac(p)==2 && BalanceFac(p->lchild)==1)    p=LLRotation(p);
    if(BalanceFac(p)==-2 && BalanceFac(p->rchild)==-1)    p=RRRotation(p);
    if(BalanceFac(p)==2 && BalanceFac(p->lchild)==-1)    p=LRRotation(p);
    if(BalanceFac(p)==-2 && BalanceFac(p->rchild)==1)    p=RLRotation(p);
    if(BalanceFac(p)==-2 && BalanceFac(p->rchild)==0)    p=RLRotation(p);
    if(BalanceFac(p)==2 && BalanceFac(p->lchild)==0)    p=RLRotation(p);

    return p;
}

int main(){
    AVL rd;
    for(int i=0;;i++){
        cout<<"Insert the element and press -1 for stop insertion : ";
        int x;
        cin>>x;
        if(x==-1)   break;
        // rd.Insert(rd.getroot(),x);
        rd.setroot(rd.Insert(rd.getroot(),x));
    }

    rd.Preorder(rd.getroot());
    int y;
    cout<<endl<<"Which number you want to delete : ";
    cin>>y;
    rd.setroot(rd.Delete(rd.getroot(),y));
    rd.Preorder(rd.getroot());
    
    return 0;
}