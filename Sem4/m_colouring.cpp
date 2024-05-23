#include<iostream>
#include<fstream>
using namespace std;

const int N = 100;
int graph[N][N];

bool possible(int v,int node,int col,int colour[]){
    for(int k=0;k<v;k++){
        if(graph[k][node] == 1 && colour[k] == col) return 0;
    }
    return 1;
}

bool solve(int m,int v,int colour[],int node){
    if(node == v){
        for(int i=0;i<v;i++){
            cout<<colour[i]<<" -> ";
        }
        cout<<endl;
        return 1;
    }

    for(int i=1;i<=m;i++){
        if(possible(v,node,i,colour)){
            colour[node] = i;
            if(solve(m,v,colour,node+1))    ;
            
            colour[node] = 0;   //Backtring
        }
    }
    return 0;
}

bool GraphColouring(int m,int v){
    int colour[v] = {0};
    if(solve(m,v,colour,0)) return 1;
    return 0;
}

int main(){
    int e,v;
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

    int m;
    cout<<"Give the possible number : ";
    cin>>m;

    if(GraphColouring(m,v)){
        cout<<"Colouring is possible"<<endl;
    }
    else{
        cout<<"Colouring is not possible"<<endl;
    }

    return 0;
}