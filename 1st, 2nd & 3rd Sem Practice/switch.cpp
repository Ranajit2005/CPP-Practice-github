#include<iostream>
using namespace std;
int main(){
    char ch;
    cout<<"Enter the opwrators : ";
    cin>>ch;
    switch(ch){
        case '+':cout<<"add";
        break;
        case '-':cout<<"Substrak";
        break;
        case '*':cout<<"Multiply";
        break;
        case '/':cout<<"Devisor";
        break;
        default:cout<<"Wrong";
    }
    return 0;
}