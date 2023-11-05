#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cout<<"Give the Size of Array : ";
    cin>>n;

    vector<int>v(n+1); // here we follow 1 base index

    cout<<"Give the element of Array ";
    for(int i=1;i<v.size();i++){
        cin>>v[i];
    }
    // calculate prefix sum
    for(int i=1;i<v.size();i++){
        v[i]+=v[i-1];
    }
    int r,l;
    cin>>r>>l;

    int ans=v[l]-v[r];

    cout<<ans;

    // for(int i=1;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }

    return 0;
    
}