#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cout<<"The value of a :";
    cin>>a;
    cout<<"The value of b :";
    cin>>b;
    c=a;
    a=b;
    b=c;
    cout<<"The value of a is :"<<a;
    cout<<"\nThe value of b is :"<<b;
    return 0;
}