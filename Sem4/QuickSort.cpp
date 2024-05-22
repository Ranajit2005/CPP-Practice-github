#include<iostream>
using namespace std;

int partition(int arr[],int low,int high){
    int pivot = arr[high];
    int i = low;
    int j = low - 1;
    for(;i<=high;i++){
        if(arr[i]<pivot){
            j++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[j+1],arr[high]);
    return j+1;
}

void QuickSort(int arr[],int low,int high){
    if(low<high){
        int pos = partition(arr,low,high);
        QuickSort(arr,low,pos-1);
        QuickSort(arr,pos+1,high);
    }
}

int main(){
    int n;
    cout<<"Give the number of the elements : ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    QuickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}