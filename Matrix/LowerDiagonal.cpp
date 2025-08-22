#include<bits/stdc++.h>
using namespace std;


class LowerDiagonal{
    private:
        int diamention;
        int *A;
        int size;

    public:
        LowerDiagonal(int diamention){
            this->diamention = diamention;
            this->size = ((diamention * (diamention + 1))/2);
            A = new int[size];
        }
    
    void Create();
    void Display();
    void GetElement();
};

void LowerDiagonal :: Create(){
    for(int i=0;i<size;i++){

        int r,c,ele;
        cout<<"Give row, col, ele following 0 based indexing : ";
        cin>>r>>c>>ele;

        if(r < c){
            cout<<"Give proper position ";
            exit(0);
        }
        A[((r * (r + 1)) / 2) + c] = ele;
    }
}

void LowerDiagonal :: Display(){
    for(int i=0;i<diamention;i++){
        for(int j=0;j<diamention;j++){
            if(i>=j){
                cout<<A[((i * (i + 1)) / 2) + j]<<" ";
            }else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}

void LowerDiagonal :: GetElement(){
    int r,c;
    cout<<"Give row and col for accessing element : ";
    cin>>r>>c;
    cout<<A[((r * (r + 1)) / 2) + c]<<"HI............"<<endl;
}

int main(){
    int n,r,c;
    cout<<"Give the diamention : ";
    cin>>n;

    LowerDiagonal ld(n);

    ld.Create();
    ld.Display();
    ld.GetElement();

    return 0;
}