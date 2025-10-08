#include<bits/stdc++.h>
using namespace std;


class SymeticMatric{
    private:
        int diamention;
        vector<vector<int>> V;
    public:
        // SymeticMatric(int d){
            
        // }

        void Create();
};

void SymeticMatric :: Create(){
    for(int i=0;i<diamention;i++){
        for(int j=0;j<diamention;j++){
            cout<<"Give "<<i<<"th row and "<<j<<"th column : ";
            int ele;
            cin>>ele;
            V[i][j] = ele;
        }
    }
}


int main(){

    return 0;
}