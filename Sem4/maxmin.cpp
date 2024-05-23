#include<iostream>
using namespace std;

void FindMaxMin(int arr[],int low,int high,int *max,int *min){
    if(low == high){
        *max = *min = arr[low];
    }else if(low == high+1){
        if(arr[low] > arr[high]){
            *max = arr[low];
            *min = arr[high];
        }else{
            *max = arr[high];
            *min = arr[low];
        }
    }else{
        
    }
}

int main(){
    int n,max,min;
    cout<<"Give the size of the element : ";
    cin>>n;

    int arr[n];
    
    cout<<"Give the element : ";
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    FindMaxMin(arr,0,n-1,&max,&min);

    return 0;
}