#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void CountSort(vector<int>&v,int pos){
    int n=v.size();
    //create freq vector
    vector<int>freq(10,0);
    for(int i=0;i<n;i++){
        freq[(v[i]/pos)%10]++;
    }
    //cumulative vector
    for(int i=1;i<10;i++){
        freq[i]=freq[i]+freq[i-1];
    }
    //create ans vector
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
       ans[--freq[(v[i]/pos)%10]]=v[i]; 
    }
    //store it in its main vector
    for(int i=0;i<n;i++){
        v[i]=ans[i];
    }
}

void RadixSort(vector<int>&v){
    //finding max element
    int maxele=INT_MIN;
    for(int i=0;i<v.size();i++){
        maxele=max(maxele,v[i]);
    }
    //finding its position
    for(int pos=1;maxele/pos>0;pos*=10){
        CountSort(v,pos);
    }
}

int main(){
    int n;
    cout<<"Give the size of the vestor : ";
    cin>>n;

    vector<int>v(n);
    cout<<"Give the elements of the vector : ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    RadixSort(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}