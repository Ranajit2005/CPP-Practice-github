#include<iostream>
using namespace std;

int BinarySearch(int arr[],int n,int element){
    int low = 0, high = n;

    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == element){
            return mid;
        }else if(arr[mid]<element){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    return -1;
}

int main(){
    int n , element;
    cout<<"Give the size of the element : ";
    cin>>n;

    int arr[n];
    
    cout<<"Give the element is sorted order : ";
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Which elemnt you want ro fine : ";
    cin>>element;

    int pos = BinarySearch(arr,n,element);

    if(pos == -1){
        cout<<"Element is not found "<<endl;
    }else{
        cout<<"Element placed in index number "<<pos<<endl;
    }

    return 0;
}