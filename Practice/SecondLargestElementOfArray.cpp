#include<iostream>
using namespace std;

int Largeind(int arr[],int n){
    int max = 0;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=i;
        }
    }
    return max;
}

int main(){
    int arr[]{1,2,3,9,5,6,7,9};
    int size=sizeof(arr)/sizeof(arr[0]);

    int largeIndex = Largeind(arr,size);

    // if largest is repeated like {1,6,2,6,3}

    for(int i=0;i<size;i++){
        if(arr[largeIndex]==arr[i]){
            arr[i]=-1;
        }
    }
    arr[largeIndex] = -1;

    int SecondLar = Largeind(arr,size);
    cout<<"The Second Largest Element is "<<arr[SecondLar];
    
    return 0;
}