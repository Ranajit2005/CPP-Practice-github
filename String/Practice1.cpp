#include <bits/stdc++.h>
using namespace std;

int main(){

    char a = '\0';
    // printf("%d",a);

    char b = a + 65;

    cout<<b<<endl;
    // string s;
    // char str[3] = {'A','B','C'};
    // char str1[] = {'A','B','C'};
    // char str2[] = "name";


    // char str[50];
    // gets(str);

    // int len,i=0;

    // while(str[i]!='\0'){
    //     i++;
    // }
    
    // cout<<"The length is "<<i<<endl;
    // if(str[3] == '\0') cout<<"I am hare";
    // cout<<str[3];


    string s;
    getline(cin,s);
    int len = 0;
    while(s[len]!='\0') len++;
    cout<<len<<endl;
    cout<<s;

    return 0;
}
