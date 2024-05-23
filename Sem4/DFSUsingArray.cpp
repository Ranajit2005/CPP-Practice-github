#include<iostream>
#include<fstream>
using namespace std;

const int N = 100;
bool visited[N] = {0};
int graph[N][N];

void DFS(int src,int v){
    cout<<src<<" ";
    visited[src] = 1;

    for(int i=0;i<v;i++){
        if(graph[src][i] == 1 && !visited[i]){
            DFS(i,v);
        }
    }
}

int main(){
    int e,v,src;
    fstream infile;
    infile.open("GraphRead.txt",ios::in);
    if(!infile){
        cout<<"There is no such file"<<endl;
    }
    infile>>v>>e;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            infile>>graph[i][j];
        }
    }

    cout<<"Give the starting vertex : ";
    cin>>src;
    DFS(src,v);

    return 0;
}