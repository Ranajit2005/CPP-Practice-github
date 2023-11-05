#include<iostream>
using namespace std;

class Complex{
    int real,imaginary;
    public:
    void setdata(int,int);
    void display(){
        cout<<"The real part is : "<<real<<"\n";
        cout<<"The imaginary part is : "<<imaginary<<endl;
    }

};
void Complex :: setdata(int a,int b){
    real=a;
    imaginary=b;
}
int main(){
    // Complex c;
    // c.setdata(3,5);
    // c.display();
    Complex *rd = new Complex[3];
    rd->setdata(3,5);
    rd++ ->display();
    rd->setdata(5,6);
    rd++ ->display();
    rd->setdata(7,9);
    rd++ ->display();
    rd->setdata(9,9);
    rd++ ->display();
    rd->setdata(7,9);
    rd++ ->display();
    rd->setdata(9,9);
    rd++ ->display();
return 0;
}