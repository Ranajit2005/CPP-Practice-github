#include <iostream>
using namespace std;
class Y;

class X
{
    int a;
    friend void add(X r, Y d);

public:
    void setValue(int x)
    {
        a = x;
    }
};

class Y
{
    int b;

public:
    friend void add(X r, Y d);
    void setValue(int y)
    {
        b = y;
    }
};

void add(X o1, Y o2)
{
    cout << "The sum of two number is : " << o1.a + o2.b << endl;
}

int main()
{

    X r1;
    Y r2;

    r1.setValue(3);
    r2.setValue(9);
    add(r1, r2);

    return 0;
}