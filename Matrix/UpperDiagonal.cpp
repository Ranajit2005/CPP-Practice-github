#include<bits/stdc++.h>
using namespace std;


class UpperDiagonal{
    private:
        int diamention;
        int *A;
        int size;

    public:
        UpperDiagonal(int diamention){
            this->diamention = diamention;
            this->size = ((diamention * (diamention + 1))/2);
            A = new int[size];
        }

        ~UpperDiagonal(){
            delete[] A;
        }
    
    void Create();
    void Display();
    void GetElement();
};

void UpperDiagonal :: Create(){
    for(int i=0;i<size;i++){

        int r,c,ele;
        cout<<"Give row, col, ele following 0 based indexing : ";
        cin>>r>>c>>ele;

        if(r > c){
            cout<<"Give proper position ";
            exit(0);
        }
        A[(((r * diamention) - ((r * (r - 1)))/2) + c)] = ele;
    }
}

void UpperDiagonal :: Display(){
    for(int r=0;r<diamention;r++){
        for(int c=0;c<diamention;c++){
            if(r<=c){
                cout<<A[(((r * diamention) - ((r * (r - 1)))/2) + c)]<<" ";
            }else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}

void UpperDiagonal :: GetElement(){
    int r,c;
    cout<<"Give row and col for accessing element : ";
    cin>>r>>c;

    if(r > c){
        cout<<"Give proper position ";
        exit(0);
    }
    cout<<A[(((r * diamention) - ((r * (r - 1)))/2) + c)]<<endl;
}

int main(){
    int n,r,c;
    cout<<"Give the diamention : ";
    cin>>n;

    UpperDiagonal ud(n);

    ud.Create();
    ud.Display();
    ud.GetElement();

    return 0;
}