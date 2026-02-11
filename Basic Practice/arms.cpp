#include<iostream>
#include<cmath>
using namespace std;

int main(){
    
    int num,test,sum=0,r=0,new_num = 0;
    cout<<"Give the number : ";
    cin>>num;
    
    test = num;

    while(test>0){
        sum++;
        test=test/10;
        cout<<sum<<" "<<test<<endl;
    }

    test = num;
    while(test > 0){
        r = test % 10;

        // int val1 = round(pow(5,3));
        // int val2 = pow(5,3);
        // cout<<r<<"-"<<sum<<"-"<<val1<<endl;
        // cout<<r<<"-"<<sum<<"-"<<val2<<endl;

        new_num = new_num + round(pow(r,sum));

        test=test/10;
    }

    if(num == new_num) cout<<"Amstrong number ";
    else cout <<"Not amstrong number";

    return 0;
}