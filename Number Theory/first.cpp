#include<bits/stdc++.h>
using namespace std;

void print(int number){
    for(int i=10;i>=0;i--){
        cout<<((number >> i) & 1);
    }
    cout<<endl;
}

int main(){
    print(5);

    cout<< ((5 >> 1) & 1) <<endl;

    return 0;
}