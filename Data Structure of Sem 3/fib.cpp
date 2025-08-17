#include<iostream>
using namespace std;

int FibonacciTailRecursive(int n, int previous, int current)
{
    if (n == 0){
        return previous;
    }
    if (n == 1){
        return current;
    }
        cout<<previous<<" ";
        // cout<<current<<" ";
    
    return FibonacciTailRecursive(n - 1, current, previous + current);
}

int main(){
    // Fibo(5,0,1);
    int n;
    cout<<"Give the size : ";
    cin>>n;
    FibonacciTailRecursive(n+1,0,1);
    return 0;
}