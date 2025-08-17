#include<iostream>
using namespace std;
int main(){
    int arr[]={1,9,5,7,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 3;
    bool flag = true;
    int ele = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==key){
        flag = false;
        ele = i;
        break;
        }
    }
    if (flag == true) cout<< "no";
    else cout << ele;
    return 0;
}