#include <iostream>
using namespace std;

class Fruit
{
public:
    string name; // this are properties
    string color;
    int rateing;
};

int main()
{
    Fruit apple; // it is object
    apple.name = "Apple";
    apple.rateing = 10;
    apple.color = "red";
    cout << apple.color << " " << apple.name << " " << apple.rateing << endl;

    Fruit mango; // it is object
    mango.color = "Yellow";
    mango.name = "Mango";
    mango.rateing = 9;
    cout << mango.color << endl
         << mango.name << endl
         << mango.rateing << endl;
         
    return 0;
}