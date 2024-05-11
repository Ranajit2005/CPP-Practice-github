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
    
    int ks[size][maxwt+1];

    //here we manually initialise it with 0 because here we take input of the array
    for(int i=0;i<size;i++){
        for(int j=0;j<=maxwt;j++){
            ks[i][j] = 0;
        }
    }

    for(int i=1 ;i <=n; i++){
        for(int w=1; w<=maxwt; w++){
            if(weight[i] <= w){
                ks[i][w] = max(ks[i-1][w], ks[i-1][w-weight[i]]+profit[i]);
            }else{
                ks[i][w] = ks[i-1][w];
            }
        }
    }   

    cout<<"The maximum profit is : "<<ks[n][maxwt]<<endl;

    //Code for which items are include
    int i = n,j = maxwt;
    while(i>0 && j>=0){
        if(ks[i][j] == ks[i-1][j]){
            cout<< i <<" th item is not included"<<endl;
            i--;
        }else{
            cout<< i <<" th item is included"<<endl;
            j = j - weight[i];  //Find for remaining weight
            i--;
        }
    }
    cout<<endl;

    return 0;
}