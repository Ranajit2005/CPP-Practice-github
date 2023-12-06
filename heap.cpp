#include<iostream>
using namespace std;

void InsertForMaxHeap(int arr[],int n){
    int temp,i=n;
    temp = arr[n];
    while(i>1 && temp>arr[i/2]){
        arr[i] = arr[i/2];
        i = i/2;
    }
    arr[i] = temp;
}

int main(){
    int n;
    cout<<"Give the size of the array : ";
    cin>>n;
    int size = n + 1;   //for 1 base index
    int arr[size];
    arr[0]=0;   //because here we don't use index 0
    for(int i=1;i<size;i++){    //start from index 1
        cout<<"Give the element of the array at index "<<i<<" : ";
        cin>>arr[i];
        InsertForMaxHeap(arr,i);
        // cout<<endl;
    }



    for(int i=1;i<size;i++){
        cout<<arr[i]<<" ";
    }
return 0;
}