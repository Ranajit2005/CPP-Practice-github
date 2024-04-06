#include<iostream>
using namespace std;

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

int main(){
    int v,e;
    cout<<"Enter the number of veritices : ";
    cin>>v;
    cout<<"Enter the number of edges : ";
    cin>>e;

    
    return 0;
}