#include<iostream>
using namespace std;

int main(){
    int a;
    cout<<"How many line you want to print : ";
    cin>>a;
    for(int i=0;i<a;i++){   // row number
        for(int j=0;j<i;j++){   //space number
            cout<<" ";
        }
        for(int k=0;k<2*a-2*i-1;k++){   //star number
            cout<<"*";
        }
        // for(int k=2*a-2*i-1;k>0;k--){
        //     cout<<"*";
        // }
        cout<<endl;
    }
return 0;
}