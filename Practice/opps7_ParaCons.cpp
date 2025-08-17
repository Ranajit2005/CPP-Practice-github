#include <iostream>
using namespace std;

class complex
{
    int a, b;

public:
    complex() {} // Default Constractor
    complex(int, int);
    void show_num()
    {
        cout << "The number is : " << a << " + " << b << "i" << endl;
    }
};

complex ::complex(int x, int y)
{
    a = x;
    b = y;
}

int main()
{
    // complex rd;
    complex rd(3,4);
    rd.show_num();
    return 0;
}