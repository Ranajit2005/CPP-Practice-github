#include<iostream>
using namespace std;
class Y;
class X{
    int a;
    public:
    friend void swap(X &,Y &);
    void fun1(int x){
        a = x;
    }
    void display(){
        cout << "The 1st Number is : "<<a<<endl;
    }
};

class Y{
    int b;
    friend void swap(X &,Y &);
    public :
    void fun2(int y){
        b = y;
    }
    void display(){
        cout << "The 2nd Number is : "<<b<<endl;
    }
};

void swap(X &o1,Y &o2){
    int temp = o1.a;
    o1.a=o2.b;
    o2.b=temp;


}

int main(){
    X r1;
    Y r2;
    r1.fun1(5);
    r2.fun2(7);
    swap(r1,r2);
    r1.display();
    r2.display();
return 0;
}