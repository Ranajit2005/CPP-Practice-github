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

void Delete(int arr[],int n){   //Delete is possible only from rrot
    int x,i,j;
    x = arr[n];     //store root at a variable
    arr[1] = arr[n];    //Delete root
    i = 1;
    j = 2 * i;
    while(j<n-1){
        if(arr[j+1]>arr[j])     j = j+1;    //Check which is bigger bigger between left or right child
        if(arr[i]<arr[j]){      //Check whichn is bigger between parent and child
            swap(arr[i],arr[j]);
            i=j;
            j=2*i;
        }
        else    break;
    }
    arr[n] = x;
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

    cout<<"After insert the array is : ";
    for(int i=1;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    for(int i=size;i>1;i--){
        Delete(arr,i);
    }

    cout<<"The sorted array is : ";
    for(int i=1;i<size;i++){
        cout<<arr[i]<<" ";
    }
return 0;
}