#include<iostream>
using namespace std;

int main(){
    int n,maxwt;
    cout<<"Give the items number: ";
    cin>>n;
    int size = n + 1;   //because we follow 1 base indexing 

    int profit[size] = {0};
    int weight[size] = {0};

    for(int i = 1;i < size;i++){
        cout<<"Give the weight and profite of the "<<i<<" th element : ";
        cin>>weight[i]>>profit[i];
    }

    cout<<"Give the maximum capacity : ";
    cin>>maxwt;
    
    int ks[size][maxwt+1] = {0};

    for(int i=0 ;i < size; i++){
        for(int w=0; w<=maxwt; w++){
            if(weight[i] <= w){
                ks[i][w] = max(ks[i-1][w], ks[i-1][w-weight[i]]+profit[i]);
            }else{
                ks[i][w] = ks[i-1][w];
            }
        }
    }   

    cout<<"The maximum profit is : "<<ks[size][maxwt+1]<<endl;

    for(int i=0;i<size;i++){
        for(int j=0;j<=maxwt;j++){
            cout<<ks[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}