#include<iostream>
#include<limits.h>
#include<vector>

using namespace std;

void CountSort(vector<int>&v){
    int n=v.size();

    // finding maximum element
    int maxele=INT_MIN;
    for(int i=0;i<n;i++){
        maxele=max(v[i],maxele);
    }

    // create a freq vector of (maxele + 1) size and fill it
    vector<int>freq(maxele+1,0);
    for(int i=0;i<n;i++){
        freq[v[i]]++;
    }

    // create cumulative vector(where we sum this and previous element)
    for(int i=1;i<=maxele;i++){
        freq[i]+=freq[i-1];
    }

    // calculate the answer sorted vcetor
    // we start from last because it will be stable
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        ans[--freq[v[i]]]=v[i];
    }

    // put it in its original vector
    for(int i=0;i<n;i++){
        v[i]=ans[i];
    }
}

int main(){
    int n;
    cout<<"Give the size of the Vector : ";
    cin>>n;
    cout<<"Give the element of the vector ";
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    CountSort(v);

    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}