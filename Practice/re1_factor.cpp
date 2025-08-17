#include<iostream>
using namespace std;

int factor(int n){
    if(n==0)    return 1;   //Base Case
    return n*factor(n-1);   //Assum And Self Work
}

int main(){
    int n;
    cout<<"Give a positive number : ";
    cin>>n;
    // int resust;
    int resust = factor(n);
    cout<<"The factorial of this number is : "<<resust;

    return 0;
}
