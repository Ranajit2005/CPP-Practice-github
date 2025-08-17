#include<iostream>
using namespace std;

class polinomial{
    int x1,x2,x3;
    public:

    polinomial(int a,int b,int c){
        x1 = a;
        x2 = b;
        x3 = c;
    }
    polinomial operator + (polinomial obj){
        polinomial temp(0,0,0);
        temp.x1 = x1 + obj.x1;
        temp.x2 = x2 + obj.x2;
        temp.x3 = x3 + obj.x3;
        return temp;
    }
    void display();
};

void polinomial :: display(){
    cout<<"After addition the number is : "<<x1<<"x + "<<x2<<"x^2 + "<<x3<<"x^3";
}

int main(){

    polinomial p1(1,2,3),p2(1,2,3),p3(1,2,3);
    polinomial res = p1 + p2 + p3;
    res.display();
    return 0;
}