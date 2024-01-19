#include <iostream>
using namespace std;

class Complex
{
    int real, img;

public:
    void input();
    Complex operator+(Complex obj)
    {
        Complex temp;
        temp.real = real + obj.real;
        temp.img = img + obj.img;
        return temp;
    }
    void display()
    {
        cout << "The number is : " << real << "+ " << img << "i" << endl;
    }
};

void Complex ::input()
{
    cout << "Enter real part : ";
    cin >> real;
    cout << "Enter imaginary part : ";
    cin >> img;
}

int main()
{
    Complex com1, com2, res;
    cout << "Enter the 1st complex number : " << endl;
    com1.input();
    cout << "Enter the 2nd complex number : " << endl;
    com2.input();
    res = com1 + com2;
    res.display();

    return 0;
}