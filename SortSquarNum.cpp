#include<iostream>
#include<vector>

using namespace std;

void Sort(vector<int>&v,int n){

    // vector<int>ans(n);
    // for(int i=0;i<v.size();i++){
    //     ans[i]=abs(v[i]);
    // }

    // for(int i=0;i<v.size();i++){
    //     v[i]=ans[i]*ans[i];
    // }

    for(int i=0;i<v.size();i++){
        v[i]*=v[i];
    }

    for(int i=0;i<n-1;i++){
        // bool flag = false;
        for(int j=0;j<n-1-i;j++){
            if(v[j]>v[j+1]){
                // flag = true;
                swap(v[j],v[j+1]);
            }
            // if(flag=false) break;
        }
    }

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

    return;
}


int main(){
    int n;
    cout<<"give Size : ";
    cin>>n;

    vector<int>v(n);

    for(int i=0;i<v.size();i++){
        cin>>v[i];
    }

    Sort(v,n);
    
    return 0;

}