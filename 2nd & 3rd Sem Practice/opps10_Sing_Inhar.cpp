#include <iostream>
using namespace std;

class Base
{
    int data1;

public:
    int data2;
    void setdata(int, int);
    int getdata1();
    int getdata2();
};
void Base ::setdata(int x, int y)
{
    data1 = x;
    data2 = y;
}
int Base ::getdata1()
{
    return data1;
}
int Base ::getdata2()
{
    return data2;
}
class Derive : public Base
{
    int data3;

public:
    ;
    void gatedata3(int a)
    {
        data3 = a;
    }
    void process();
    void display();
};
void Derive ::process()
{
    data2 = data2 * data3;
}
void Derive ::display()
{
    cout << "The value of data1 is : " << getdata1() << endl;
    cout << "The value of data3 is : " << data3 << endl;
    cout << "The value of final data2 is : " << data2 << endl;
    // cout<<"The final value of data2 is : "<<endl;
}
int main()
{
    Derive rd;
    rd.setdata(3, 4);
    rd.gatedata3(10);
    rd.display();
    rd.process();
    return 0;
}