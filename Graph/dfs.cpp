#include<iostream>
#include<vector>
using namespace std;

const int N = 100;
bool visited[N] = {0};
vector<int>graph[N];

void DFS(int src){
    visited[src] = 1;
    cout<<src<<" ";
    for(int child : graph[src]){
        if(visited[child])  continue;
        // cout<<child<<" ";
        DFS(child);     //using recurtion, here we use stack
    }
}

int main(){
    int e,a;
    cout<<"Give the edges number : ";
    cin>>e;

    for(int i = 0;i <e ;i++){
        int v1,v2;
        cout<<"Which two vertices are connected : ";
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    cout<<"From which vertices you want to start dfs : ";
    cin>>a;
    DFS(a);

    return 0;
}