#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* lchild;
    Node* rchild;
    Node(int x){
        data = x;
        lchild = nullptr;
        rchild = nullptr;
    }
};

class BST{
    Node* root;
public:
    BST(){
        root = nullptr;
    }
    Node* getroot(){
        return root;
    }
    void Setroot(Node* temp){
        root = temp;
    }
    void Insert(int key){
        Node* t = root;
        Node* p =new Node(key);
        Node* r;
        if(root == nullptr){
            root = p;
            return;
        }
        while(t!=nullptr){
            r = t;
            if(key<t->data){
                t = t->lchild;
            }
            else{
                t = t->rchild;
            }
        }
        if(key < r->data){
            r->lchild = p;
        }else{
            r ->rchild = p;
        }
    }
        void Inorder(Node* );
        void Preorder(Node* );
        void Postorder(Node* );
        int CountNode(Node* );
        int LeafNode(Node* );
        int Hight(Node* );
        Node* IP(Node* head){
            Node* p=head;
            p=p->lchild;
            while(p->rchild){
                p = p->rchild;
            }
            return p;
        }
        Node* IS(Node* head){
            Node* p =head;
            p=p->rchild;
            while(p->lchild){
                p = p->lchild;
            }
        }
        Node* Delete(int key,Node* p){
            if(p == nullptr)    return nullptr;
            if(p->lchild == nullptr && p->rchild ==nullptr && key == p->data){
                if(p == root)   root = nullptr;
                delete p;
                return nullptr;
            }
            Node* temp;
            if(key<p->data) p->lchild = Delete(key,p->lchild);
            else if(key>p->data)    p->rchild = Delete(key,p->rchild);
            else{
                temp = IP(p);
                p->data = temp->data;
                p->lchild = Delete(temp->data,p->lchild);
            }
            return p;
        }
};

void BST :: Inorder(Node* p){
    if(p){
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}

void BST :: Preorder(Node* p){
    if(p){
        cout<<p->data<<" ";
        Preorder(p->rchild);
        Preorder(p->lchild);
    }
}

void BST :: Postorder(Node* p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout<<p->data<<" ";
    }
}

int BST :: CountNode(Node* p){
    int x = 0, y = 0;
    if(p){
        x = CountNode(p->lchild);
        y = CountNode(p->rchild);
        return x+y+1;
    }
    return 0;
}

int BST :: LeafNode(Node* p){
    int x = 0, y = 0;
    if(p){
        x = LeafNode(p->lchild);
        y = LeafNode(p->rchild);
        if(p->lchild==NULL && p->rchild==NULL){
        return x+y+1;
        }
        return x+y;
    }
    return 0;
}

int BST :: Hight(Node* p){
    int lh = 0, rh =0;
    if(p == nullptr){
        return -1;
    }else{
        lh = Hight(p->lchild);
        rh = Hight(p->rchild);
        if(lh>rh)   return lh+1;
        else return rh+1;
    }
    return 0;
}

int main(){

    BST rd;
    rd.Insert(30);
    rd.Insert(5);
    rd.Insert(10);
    rd.Insert(60);
    rd.Insert(20);
    rd.Insert(70);
    rd.Insert(7);
    // rd.Insert(55);

    rd.Inorder(rd.getroot());
    // cout<<endl;
    // rd.Preorder(rd.getroot());
    // cout<<endl;
    // rd.Postorder(rd.getroot());
    cout<<endl<<rd.CountNode(rd.getroot())<<endl;
    cout<<rd.LeafNode(rd.getroot())<<endl;
    cout<<"Total Intarnal Nodes are : "<<rd.CountNode(rd.getroot())-rd.LeafNode(rd.getroot())<<endl;
    cout<<rd.Hight(rd.getroot())<<endl;
    rd.Setroot(rd.Delete(10,rd.getroot()));
    rd.Inorder(rd.getroot());
    return 0;
}