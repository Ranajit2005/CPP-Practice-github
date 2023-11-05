#include<iostream>
using namespace std;
int main(){
    float x,y,z;
    cout<<"Enter you 1st sem SGPA : ";
    cin>>x;
    cout<<"Enter you 1st sem SGPA : ";
    cin>>y;
    z = (((((x + y) / 2) - .75) * 10)*1400)/100;
    float r = (z * 1400) / 100;
    cout<<"You get marks : "<<z;
    return 0;
}