#include<iostream>
using namespace std;

class A{
    int a;
    public :
    void setdata(int a){
        this->a=a;
    }
    void display(){
        cout<<"The value of a is : "<<a;
    }
};

class B{
    int a;
    public :
    B &setdata(int a){
        this->a=a;
        return *this;
    }
    void display(){
        cout<<"The value of a is : "<<a;
    }
};

int main(){
    // A a;
    // a.setdata(9);
    // a.display();
    B r;
    r.setdata(10).display();
    return 0;
}