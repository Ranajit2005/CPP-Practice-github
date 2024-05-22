#include<iostream>
using namespace std;

void Merge(int arr[],int low,int mid,int high){
    int help[100];
    int i = low,j = mid+1,k = low;

    while(i<=mid && j<=high){
        if(arr[i]<arr[j])    help[k++] = arr[i++];
        else    help[k++] = arr[j++];
    }

    for(;i<=mid;i++){
        help[k++] = arr[i];
    }

    for(j;j<=high;j++){
        help[k++] = arr[j];
    }

    for(int i=0;i<=high;i++){
        arr[i] = help[i];
    }
}

void MergeSort(int arr[],int low,int high){
    int mid = (low + high)/2;
    if(low<high){
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        Merge(arr,low,mid,high);
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
    MergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}