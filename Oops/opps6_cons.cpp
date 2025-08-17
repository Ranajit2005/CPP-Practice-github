#include <iostream>
using namespace std;

class complex
{
    int a, b;

public:
    complex(void);
    void show_num()
    {
        cout << "The number is : " << a << " + " << b << "i" << endl;
    }
};

complex ::complex()
{
    a = 10;
    b = 11;
}

int main()
{
    complex rd;
    rd.show_num();
    return 0;
}