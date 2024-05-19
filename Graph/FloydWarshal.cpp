#include<iostream>
using namespace std;
#define INF 999

int dist[100][100];

int main(){

    for(int i=0;i<100;i++){
        for(int j =0;j<100;j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    int v,e;
    cout<<"Give vertex no and egde number : ";
    cin>>v>>e;

    for(int i=0;i<e;i++){
        int x,y,wt;
        cout<<"Give which vertex to which vertex and weight : ";
        cin>>x>>y>>wt;
        dist[x][y] = wt;
    }

    for(int k=1;k<=v;k++){
        for(int i=1;i<=v;i++){
            for(int j=0;j<=v;j++){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    cout<<"After Floyd Warshall the matrix is : "<<endl;
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            if(dist[i][j] == INF)   cout<<"I ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}