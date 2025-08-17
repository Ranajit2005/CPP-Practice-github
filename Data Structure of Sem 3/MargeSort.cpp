#include<iostream>
using namespace std;

void Marge(int arr[],int l,int mid,int h){
    int help[100];
    int i = l,j = mid +1,k = l;
    while(i<=mid && j<=h){
        if(arr[i]>arr[j]){
            help[k++]=arr[j++];
        }else{
            help[k++]=arr[i++];
        }
    }
    for(;i<=mid;i++){
        help[k++]=arr[i];
    }
    for(;j<=h;j++){
        help[k++]=arr[j];
    }

    for(int i=l;i<=h;i++){
        arr[i]=help[i];
    }
}

void MargeSort(int arr[],int l,int h){
    if(l<h){
        int mid =(l + h)/2; 
        MargeSort(arr,l,mid);
        MargeSort(arr,mid +1,h);
        Marge(arr,l,mid,h);
    }
}

int main(){
    int arr[]={12,67,12,5,1,4,2,0,6,7};
    int n=10;
    MargeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}