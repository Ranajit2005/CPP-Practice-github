#include<iostream>
#include<vector>
using namespace std;

// 1 0 0 1 1 0 1 -> 0 0 0 1 1 1 1

void Sort(vector<int> &v){

    int left=0;
    int right=v.size()-1;

    while(left<right){
        if(v[left]==1 && v[right] ==0){
            v[left] = 0 ;
            v[right] = 1;
        }
        if(v[left]==0){
            left++;
        }
        if(v[right]==1){
            right--;
        }
    }
    return;
}

int main(){

    int n;
    cout<<"Give the of Vector :";
    cin>>n;

    vector<int> v(n);
    for(int i=0;i<v.size();i++){
        cin>>v[i];
    }

    Sort(v);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

    return 0;
}