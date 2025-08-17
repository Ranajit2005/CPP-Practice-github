#include <iostream>
using namespace std;

class Shop
{
    int itemId[100];
    int itemPrice[100];
    int counter = 0;

public:
    // void Counter() { counter = 0; }
    void SetPrice();
    void Display();
};

void Shop :: SetPrice()
{
    cout << "Enter the Id of your Item : " << counter + 1 << endl;
    cin >> itemId[counter];
    cout << "Enter your Item Price : " << endl;
    cin >> itemPrice[counter];
    counter++;
}

void Shop ::Display()
{
    for (int i = 0; i < counter; i++)
    {
        cout << "The Price Id of " << itemId[i] << " is " << itemPrice[i] << endl;
    }
}

int main()
{
    Shop Ranajit;
    Ranajit.SetPrice();
    Ranajit.SetPrice();
    Ranajit.SetPrice();
    Ranajit.Display();
    return 0;
}

// int main(){
//     Shop Ranajit,Rohan,Rohit;
//     Ranajit.SetPrice();
//     Rohan.SetPrice();
//     Rohit.SetPrice();
//     Ranajit.SetPrice();
//     Ranajit.Display();
//     Rohan.SetPrice();
//     Rohit.Display();
//     return 0;
// }