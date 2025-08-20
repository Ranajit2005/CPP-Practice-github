#include<bits/stdc++.h>
using namespace std;

void Converte(char str[]){
    int i=0;
    while(str[i]!='\0'){
        if(int(str[i])>=97 && int(str[i])<=122){
            str[i]=str[i] - 32;
        }
        i++;
    }
}

void converte(string &str){
    int i=0;
    while(str[i]!='\0'){
        if(int(str[i])>=97 && int(str[i])<=122){
            str[i]=str[i] - 32;
        }
        i++;
    }
}


int main(){
    cout<<"Give the string : ";
    
    // char str[100];
    // gets(str);
    // Converte(str);

    string str;
    getline(cin,str);
    converte(str);

    cout<<"The capital string is : "<<str<<endl;

    return 0;
}