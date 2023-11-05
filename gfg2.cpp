#include<iostream>
#include<vector>
#include<math.h>
using namespace std;


int main(){
    vector<int>v[16];
    int a,b;
    cout<<"Give number : ";
    cin>>a;
    cout<<"Shifing : ";
    cin>>b;
    int x,y;
    x = a * pow(2,b);
    y = a / pow(2,b);
    cout<<x<<" "<<y;
    
    return 0;
}