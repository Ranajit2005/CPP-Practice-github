#include<iostream>
#include<fstream>
using namespace std;

int graph[100][100];

bool possible(int node,int colour[],int v,int col){
    for(int k=0;k<v;k++){
        if(k != node && graph[k][node] == 1 && colour[k] == col){
            return 0;
        }
    }
    return 1;
}

bool solve(int node,int colour[],int m,int v){

    //Base condition, means all the vertex coloured with diffrent colour and we came 0 vexter to last vectex
    if(node == v){
        return 1;
    }

    for(int i=1;i<=m;i++){
        if(possible(node,colour,v,i))    colour[node] = i;
        if(solve(node+1,colour,m,v))    return 1;
        colour[node] = 0;
    }
    return 0;

}

bool GraphColouring(int m,int v){
    int colour[v] = {0};
    if(solve(0,colour,m,v))  return 1;
    return 0;
}

void Show(int v){
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
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

    Show(v);
    int m;
    cout<<"Give the number of the colour : ";
    cin>>m;

    cout<<GraphColouring(m,v);

    return 0;
}