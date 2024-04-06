#include<iostream>
using namespace std;
int main(){
    int arr[]={1,3,4,6,7,0};
    int size=sizeof(arr)/sizeof(arr[0]);

    int n;
    cout<<"give terget : ";
    cin>>n;

    int pairs=0;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]+arr[j]==n){
                pairs++;
            }
        }
    }
    cout<<"The value of terget sum : "<<pairs;
    return 0;
}