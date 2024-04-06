#include<iostream>
using namespace std;

class complex{
    int a,b;
    public:
    complex(){}
    complex(int x,int y){
        a=x;
        b=y;
    }
    ~complex(){
        cout<<"Disrauctor is called ";
    }
    void show_display(){
        cout<<"The Values are : "<<a<<" : "<<b<<endl;
    }
};

int main(){
    complex rd(3,4);
    rd.show_display();
return 0;
}