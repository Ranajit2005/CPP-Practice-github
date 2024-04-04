#include<iostream>
#include<vector>
using namespace std;


int main(){
    int v,e;
    cout<<"Enter the number of vertices : ";
    cin>>v;
    cout<<"Enter the number of edges : ";
    cin>>e;
    vector<int>vec[50];
    for(int i=0;i<e;i++){
        int a,b;
        cout<<"Enter which vertices are connected : ";
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    
    return 0;
}