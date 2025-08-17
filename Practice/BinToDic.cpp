#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter your binary number : ";
    cin>>n;
    int ans=0;
    int power=1;

    while(n>0){
        int lastdigit=n%10;
        ans+=lastdigit*power;
        power*=2;
        n=n/10;
    }
    cout<<"The equivalent decimal numver is : "<<ans<<endl;
    
    return 0;
}