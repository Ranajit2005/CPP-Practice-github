#include<iostream>
using namespace std;

int main(){
    int arr[]={1,3,4,6,3};
    int size=sizeof(arr)/sizeof(arr[0]);

    int k,j=0;
    cout<<"How many steo you want to rotate : ";
    cin>>k;
    k=k%size;

    int ansarr[size];

    //rotate k step
    for(int i=size-k;i<size;i++){
        ansarr[j++]=arr[i];
    }

    //rotate n-k step
    for(int i=0;i<=k;i++){
        ansarr[j++]=arr[i];
    }

    //print rotate array
    for(int i=0;i<size;i++){
        cout<<ansarr[i]<<" ";
    }
    return 0;
}