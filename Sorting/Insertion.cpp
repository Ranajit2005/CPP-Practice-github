#include<iostream>
using namespace std;

void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){   //loop start from index 1
        int j = i - 1;
        int x = arr[i];
        while(j>-1 && x<arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=x;
    }
}

int main(){
    int n;
    cout<<"Give the size of the array : ";
    cin>>n;
    cout<<endl;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Give the elements at index "<<i<<" : ";
        cin>>arr[i];
    }

    insertionSort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}