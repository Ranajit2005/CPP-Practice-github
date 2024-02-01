#include<iostream>
using namespace std;

int fac(int n,int fack){
    if(n == 1){
        return fack;
    }
    return fac(n-1,n*fack);
}

int main(){

    cout<<fac(6,1);
    return 0;
}