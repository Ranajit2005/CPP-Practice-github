#include<iostream>
using namespace std;
template<class T1=int,class T2=float,class T3=int>

class A{
    T1 a;
    T2 b;
    T3 c=10;
    public :
    // void setdata(T3 c){
    //     a = c;
    //     b = 10;
    // }
    A (T1 x,T2 y,T3 z){
        a=x;
        b=y;
        c=a+b+c;
    }
    void getdata(){
        cout<<"The value of c is : "<<c<<endl;
        // cout<<"The value of b is : "<<b<<endl;
    }
};
// template<class T1>
// class B{
//     T1 = a;
// };

int main(){
    // A<int,int> rd;
    A<> rd(1,2.0,3);
    // rd.setdata(9);
    rd.getdata();
return 0;
}