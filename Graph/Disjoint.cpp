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

void Union(int v1,int v2){
    v1 = find(v1);
    v2 = find(v2);
    if(v1 != v2){
        if(size[v1]<size[v2])   swap(v1,v2);
        parent[v2] = v1;
        size[v1] += size[v2];
    }
}

int main(){
    int v,e;
    cout<<"Enter the number of veritices : ";
    cin>>v;
    cout<<"Enter the number of edges : ";
    cin>>e;

    for(int i=0;i<v;i++){
        make(i);
    }

    while(e--){
        int v1,v2;
        cout<<"Give the vertics which you want to connect : ";
        cin>>v1>>v2;
        Union(v1,v2);
    }
    
    int connect = 0;
    for(int i = 1; i<v;i++){
        if(find(i) == i) connect++;
    }

    cout<<"The disjoint sets are : "<<connect<<endl;

    return 0;
}