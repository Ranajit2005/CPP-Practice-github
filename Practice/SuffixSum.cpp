#include<iostream>
#include<vector>
using namespace std;

bool CheckPartition(vector<int>&rd){
    int preffixSum=0;
    int suffixSum=0;
    int totalSum=0;

    for(int i=0;i<rd.size();i++){
        totalSum+=rd[i];
    }

    for(int i=0;i<rd.size();i++){
        preffixSum+=rd[i];
        suffixSum = totalSum - preffixSum;
        if(preffixSum==suffixSum) return true;
    }

    return false;
}

int main(){
    int n;
    cout<<"Give the vector size : ";
    cin>>n;

    vector<int>v(n);

    for(int i=0;i<v.size();i++){
        cin>>v[i];
    }
    cout<<CheckPartition(v)<<endl;
    return 0;
}