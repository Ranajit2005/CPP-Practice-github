#include<iostream>
#include<vector>
using namespace std;

bool visited[100] = {0};
const int N = 100;
vector<int>vec[N];

void DFS(int src){
    visited[src] = 1;
    cout<<src<<" ";
    for(int child : vec[src]){
        if(visited[child])  continue;
        DFS(child);
    }
}

int main(){
    int v,e,a,b,src;
    cout<<"Give the number of vertex and edge : ";
    cin>>v>>e;

    for(int i=0;i<e;i++){
        cout<<"Give the connected vertex : ";
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    cout<<"Give the starting vertex";
    cin>>src;
    DFS(src);

    return 0;
}