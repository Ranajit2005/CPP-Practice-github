#include<iostream>
#include<fstream>
#define INF 999
using namespace std;
const int N = 100;
int graph[N][N];



int main(){
    int v,e;
    fstream infile;
    infile.open("Floyd.txt",ios::in);
    if(!infile){
        cout<<"There is no such file"<<endl;
    }
    infile>>v>>e;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            infile>>graph[i][j];
        }
    }

    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
            }
        }
    }

    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }    

    return 0;
}