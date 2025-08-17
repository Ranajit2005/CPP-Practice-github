#include<iostream>
using namespace std;

template<class T1,class T2>
float avg(T1 a,T2 b){
    float avg=(a+b)/2.0;
    return avg;
}

int main(){
    cout<<avg(9,10.99);
return 0;
}