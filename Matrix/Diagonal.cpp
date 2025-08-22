#include<bits/stdc++.h>
using namespace std;


class Diagonal{
    private:
        int diamention;
        int* A;
    public:
        Diagonal(int n){
            diamention = n;
            A = new int[n];
        }
    
        void Create(int r,int c,int ele);
        void Display();
};

void Diagonal :: Create(int r,int c,int ele){
    if(r != c) {
        cout<<"Give proper postion : "<<endl;
        return;
    }
    A[r] = ele;
}

void Diagonal :: Display(){
    for(int i=0;i<diamention;i++){
        for(int j=0;j<diamention;j++){
            if(i == j) cout<<A[i]<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
}

int main(){

    int n;
    cout<<"Give the dimention : ";
    cin>>n;

    Diagonal d(n);

    cout<<"Give the position and the element : "<<endl;
    for(int i=0;i<n;i++){
        int r,c,ele;
        cout<<"Give the row, column and element: ";
        cin>>r>>c>>ele;
        d.Create(r,c,ele);
    }

    d.Display();

    return 0;
}