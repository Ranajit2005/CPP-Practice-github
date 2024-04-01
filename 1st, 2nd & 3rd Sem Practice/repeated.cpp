#include<iostream>
using namespace std;
int main(){
    int arr[]={1,3,4,6,7,7,5,6,3};
    int size=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]==arr[j]) cout<<arr[j]<<endl;
        }
    }
    return 0;
}