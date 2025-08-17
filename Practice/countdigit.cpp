#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Give thye number";
    cin>>n;
    int digits=0;
    while(n>0){
        n=n/10;
        digits++;
    }
    cout<<"The number of digits is "<<digits;
    return 0;
}