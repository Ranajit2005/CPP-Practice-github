#include<iostream>
using namespace std;

//Space complexity is O(N^2)

int main(){
    int n, m;
    cout<<"Give the total number of vertices : ";
    cin>>n;
    cout<<"Give the total number of edges : ";
    cin>>m;
    int graph[n+1][n+1] = {0};  //here we follow 1 base indexing and inisialise with 0
    for(int i=1; i<=m ;i++){
        int v1,v2;
        cout<<"Give which two vertices are connected : ";
        cin>>v1>>v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    for (int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    

    return 0;
}