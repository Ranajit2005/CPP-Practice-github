#include<iostream>
using namespace std;

template<class T>
void swapp(T &a,T &b){  //Call By Reference
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int x,y;
    cout<<"Enter two numbers : ";
    cin>>x>>y;
    swapp(x,y);
    cout<<"The value of 1st number is : "<<x<<endl;
    cout<<"The value of 2nd number is : "<<y<<endl;
return 0;
}