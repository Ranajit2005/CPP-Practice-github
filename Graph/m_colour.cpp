#include<iostream>
#include<fstream>
using namespace std;

int graph[100][100];



void Show(int v){
    for(int i=1;i<=v;i++){
        for(int j=0;j<=v;j++){
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

    return 0;
}