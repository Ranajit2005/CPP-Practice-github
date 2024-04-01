#include <iostream>
using namespace std;

class complex
{
    
    int a, b;

public:
    void set_number(int c, int d)
    {
        a = c;
        b = d;
    }
    friend complex SumComplex(complex x, complex y);
    void show_number()
    {
        cout << "The sum of the this two comlex number is : " << a << " + " << b <<"i"<< endl;
    }
};

complex SumComplex(complex o1, complex o2)
{
    complex o3;
    o3.set_number((o1.a + o2.a), (o1.b + o2.b));
    return o3;
}

int main()
{
    complex c1, c2, sum;
    c1.set_number(2, 1);
    c1.show_number();
    c2.set_number(1, 3);
    c2.show_number();
    sum = SumComplex(c1, c2);
    sum.show_number();
    return 0;
}