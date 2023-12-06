#include<iostream>
using namespace std;


int main(){
    int n;
    int arr[n];
    cout<<"Give the size of the array : ";
    cin>>n;
    cout<<endl;
    arr[0]=0;   //becaue here we don't use index 0
    for(int i=1;i<n;i++){   //so the loop is start from 1
        cout<<"Give the element of the array in index at "<<i<<" is : ";
        cin>>arr[i];
        cout<<endl;
    }


    for(int i=1;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
return 0;
}