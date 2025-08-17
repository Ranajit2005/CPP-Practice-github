#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5};
    int *ptr=arr;
    cout<<*ptr<<endl;
    cout<<*(ptr++)<<endl;
    cout<<*(ptr++)<<endl;
    cout<<*(ptr++)<<endl;
    cout<<*(ptr++)<<endl;
    cout<<*(ptr++)<<endl;
    cout<<*(ptr++)<<endl;

    // cout<<*arr[];

    
return 0;
}