#include<iostream>
using namespace std;

int check(char ch);

int main(){
    char ch;
    cout<<"Enter something :";
    cin>>ch;
    return check(ch);
}

int check(char ch){
    // char ch;
    if(ch>=48 && ch<=57){
        cout<<"digit";
    }
    else{
        cout<<"not digit";
    }
    
}