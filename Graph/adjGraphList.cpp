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

    cout<<"The adjacence list is : "<<endl;

    for(int i=0;i<v;i++){
        for(int j=0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}