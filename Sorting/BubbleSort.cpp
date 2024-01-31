#include<iostream>
using namespace std;

void BubbleSort(int arr[],int n){
    int count = 0;
    for(int i=0;i<n-1;i++){
        bool flag = 0;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag = 1;
                count++;
            }
        }
        if(flag == 0)   break;
    }
    cout<<endl<<count<<endl;
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

    BubbleSort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}