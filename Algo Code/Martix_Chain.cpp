#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Give the total number of the matrix : ";
    cin>>n;

    int dimention[n+1];
    cout<<"Give the demention respectively ";
    for(int i=0;i<=n;i++){
        cin>>dimention[i];
    }

    // for(int i=0;i<=n;i++){
    // cout<<dimention[i]<<" ";
    // }

    

    return 0;
}

    // int arr[2*n];
    // for(int i=0;i<n;i++){
    //     cout<<"Give the dimention of "<<i + 1<<" matrix :";
    //     cin>>arr[2*i]>>arr[2*i+1];
    // }

    // int dimention[n+1];

    // for(int i=1;i<2*n;i+2){
    //     if(arr[i] != arr[i+1]){
    //         cout<<"Multiplication cannot be possible "<<endl;
    //     }
    // }

    // for(int i=0;i<2*n;i++){
    //     cout<<arr[i]<<" ";
    // }