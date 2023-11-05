#include<bits/stdc++.h>
using namespace std;

vector<int>duplicates(int arr[],int n){
    vector<int>v;
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        v[i]=arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return v;
}

int main(){
    int arr[]={1,2,3,4,5,2,3,1};
    int n=8;
    vector<int>vec;
    //duplicates(arr,n);

    sort(arr,arr+n);
    // for(int i=0;i<n;i++){
    //     v[i]=arr[i];
    // }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}