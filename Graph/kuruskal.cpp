#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//code of Disjoint set
int parent[100];
int size[100];

void make(int v){
    parent[v] = v;
    size[v] = 1;
}

int find(int v){
    if(parent[v] == v)  return v;
    return parent[v] = find(parent[v]);
}

int Union(int v1,int v2){
    v1 = find(v1);
    v2 = find(v2);
    if(v1 != v2){
        if(size[v1]<size[v2])   swap(v1,v2);
        parent[v2] = v1;
        size[v1] += size[v2];
    }
}

// <-------------------------------->

int main(){

    int v,e;
    cout<<"Give vertex and edeges numbers : ";
    cin>>v>>e;

    vector<pair<int,pair<int,int>>>vec;   // <weight,<vertex,vertex>>

    cout<<"Give input weight, vertex and vertext restectivly : ";
    for(int i=0;i<e;i++){
        int x,y,wt;
        cin>>wt>>x>>y;
        vec.push_back({wt,{x,y}});
    }

    sort(vec.begin(),vec.end());
    for(int i=0;i<v;i++)    make(i);

    int cost = 0;

    cout<<"The path is : "<<endl;

    for(auto &a : vec){
        int wt = a.first;
        int x = a.second.first;
        int y = a.second.second;

        if(find(x) == find(y))  continue;

        Union(x,y);
        cost = cost + wt;
        cout<<x<<"->"<<y<<endl;
    }

    cout<<"The total cost is "<<cost;

    return 0;
}