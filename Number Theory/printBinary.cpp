#include<bits/stdc++.h>
using namespace std;

void printBinary(int n) {
    for (int i = 5; i >= 0; i--) {
        cout << ((n >> i) & 1);
    }
    cout << endl;
}

int main(){
    int a = 9,b = 10;
    printBinary(a);
    printBinary(b);

    int c = a | b;
    printBinary(c);
    cout<<c<<endl;

    return 0;
}

