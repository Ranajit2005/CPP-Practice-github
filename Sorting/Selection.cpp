#include<iostream>
using namespace std;

void SelectionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int j,k;    //  here we take two pointer to search minimum element
        for(j=k=i;j<n;j++){     //  here j move to always
            if(arr[j]<arr[k]){
                k=j;
            }
        }
        swap(arr[i],arr[k]);
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

    SelectionSort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}