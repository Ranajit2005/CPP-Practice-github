#include<iostream>
using namespace std;

void Heapify(int arr[],int size,int i){
    int parent = i;
    int lchild = 2*i;
    int rchild = 2*i + 1;

    if(lchild<size && arr[parent]<arr[lchild]){
        parent = lchild;
    }
    if(rchild<size && arr[parent]<arr[rchild]){
        parent = rchild;
    }
    if(i!=parent){
        swap(arr[parent],arr[i]);
        Heapify(arr,size,parent);
    }
}

int main(){
    int n;
    cout<<"Give the number of the emenet : ";
    cin>>n;
    int size = n+1;
    int arr[size];
    for(int i=1;i<size;i++){
        cin>>arr[i];
    }

    for(int i=size/2;i>=1;i--){
        Heapify(arr,size,i);
    }

    for(int i=size-1;i>=1;i--){
        swap(arr[1],arr[i]);
        Heapify(arr,i,1);
    }

    for(int i=1;i<size;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}