#include<iostream>
using namespace std;

bool prime(int n){
    
    for(int i=2;i<=n/2;i++){
        if(n%i == 0) return 0;
    }
    return 1;
}


int main(){
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);

    cout<<prime(n);

    return 0;
}