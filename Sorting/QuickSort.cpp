#include<iostream>
using namespace std;

int Partision(int arr[],int low,int high){
    int pivot = arr[high];
    int i = low -1;
    int j = low;
    for(;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void QuickSort(int arr[],int low,int high){
    if(low<high){
        int pos = Partision(arr,low,high);
        QuickSort(arr,low,pos-1);
        QuickSort(arr,pos+1,high);
    }
}

int main(){
    int arr[]={1,7,2,9,4,6,3};
    QuickSort(arr,0,6);
    for(int i=0;i<=6;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}