#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> v(6);

    for(int i=0;i<v.size();i++){
        cin>>v[i];
    }
    int x;
    cout<<"Enter x :";
    cin>>x;

    int max=0;

    for(int i=0;i<v.size();i++){
        if(v[i]>x) max++;
    }

    cout<<"The value of max is "<<max;
    
    return 0;
}