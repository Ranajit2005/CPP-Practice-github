#include<iostream>
using namespace std;

class Q{
    int front;
    int rear;
    int size;
    int *Qu;
public:
    Q :: Q(int s){
        size = s;
        Qu = new int[size];
    }
};

int main(){

    return 0;
}