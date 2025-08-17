#include<iostream>
using namespace std;

void Marge(int arr[],int f,int mid,int l){
    int a=mid-f+1;
    int b=l-mid;
    //create two temp arr
    int brr[a];
    int crr[b];
    //fill those array
    for(int i=0;i<a;i++){
        brr[i]=arr[f+i];
    }
    for(int i=0;i<b;i++){
        crr[i]=arr[mid+1+i];
    }
    
    // sorting them 
    int i=0;
    int j=0;
    int k=f;
    while(i<a && j<b){
        if(brr[i]<crr[j]){
            arr[k++]=brr[i++];
        }else{
            arr[k++]=crr[j++];
        }
    }
    while(i<a){
        arr[k++]=brr[i++];
    }
    while(j<b){
        arr[k++]=crr[j++];
    }
}

void MargeSort(int arr[],int f,int l){
    // base case 
    if(f>=l) return;
    int mid=(f+l)/2;

    MargeSort(arr,f,mid); //it running untill 1 ele present in array
    MargeSort(arr,mid+1,l); //it running untill 1 ele present in array
    Marge(arr,f,mid,l); //for sorting(marge the array)
}

int main(){
    int n;
    cout<<"Give the size of array : ";
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int f=0;
    int l=n-1;
    MargeSort(arr,f,l);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}