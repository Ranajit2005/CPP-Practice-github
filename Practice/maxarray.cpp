#include<iostream>
using namespace std;
int main(){
    int arr[]={1,9,4,7,2,70};
    int n;
    int max=0;
    n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        if(arr[i]>arr[i+1]){
            max=arr[i];
        }
    }
    cout<<max;
    return 0;
}