#include <iostream>
using namespace std;

class Emplyee
{
    // private: Default case
    int a, b;

public:
    int c;
    void setDate(int x, int y, int z);
    void getData();
};

void Emplyee ::setDate(int x, int y, int z)
{
    a = x;
    b = y;
    c = z;
}

void Emplyee ::getData()
{
    cout << "The value of 1st number : " << a << endl;
    cout << "The value of 2nd number : " << b << endl;
    cout << "The value of 3rd number : " << c << endl;
}

int main()
{
    Emplyee Ranajit;
    Ranajit.setDate(12, 56, 99);
    Ranajit.getData();
    // Ranajit.a; because a is private element
    return 0;
}