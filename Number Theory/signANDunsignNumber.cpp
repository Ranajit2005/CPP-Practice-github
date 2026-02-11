#include<bits/stdc++.h>
using namespace std;


int main(){
    cout<<INT_MAX<<endl;

    int a = (1LL << 32) - 1; //2^31
    cout<<a<<endl;

    unsigned int b = (1LL << 32) - 1;
    cout << b <<endl;

    //So one bit is reserved for sign (positive or negative)

    return 0;
}