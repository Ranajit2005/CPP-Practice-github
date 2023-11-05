#include <iostream>
using namespace std;

class sul
{
public:
    int data;
    sul(int &n)
    {
        data = n;
    }
    bool isTwoPower()
    {
        data;
        while (data != 1)
        {
            data = data / 2;
            if (data % 2 != 0 && data != 1)
                return 0;
        }
        return 1;
    }
};

int main()
{
    int n;
    cout << "Give a non-negetive number : ";
    cin >> n;
    sul ans(n);
    // cout<<ans.isTwoPower();
    if (ans.isTwoPower())
        cout << "YES";
    else
        cout << "NO";
    return 0;
}