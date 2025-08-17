#include <iostream>
using namespace std;

class complex
{
    int a, b;

public:
    complex(int x, int y)
    {
        a = x;
        b = y;
    }
    complex(int x)
    {
        a = x;
        b = 0;
    }
    void show_number()
    {
        cout << "The Values are : " << a << " + " << b << "i" << endl;
    }
};
int main()
{
    complex rd(3, 4);
    complex r(5);
    rd.show_number();
    r.show_number();
    return 0;
}