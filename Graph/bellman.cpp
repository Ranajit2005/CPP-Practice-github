#include<iostream>
using namespace std;
#define INF 999

template<class t1,class t2,class t3>
class Pair{
public:
    t1 u;
    t2 v;
    t3 wt;
};

int main(){
    int v,e,src;
    cout<<"Enter the number of vertices : ";
    cin>>v;
    cout<<"Enter the number of edges : ";
    cin>>e;
    Pair<int,int,int>vec[100];
    for(int i=1;i<=e;i++){
        int a,b;
        cout<<"Enter which vertix to which vertex and give theie weight : ";
        cin>>vec[i].u>>vec[i].v>>vec[i].wt;
    }

    // cout<<"The adjacence list is : "<<endl;
    // for(int i=0;i<e;i++){
    //     cout<<vec[i].u<<" "<<vec[i].v<<" "<<vec[i].wt<<endl;
    // }

    cout<<"Give the starting vertex : ";
    cin>>src;
    int dist[v+1];      //If the graph is created form strating vectex 1
    for(int i=0;i<=v;i++){
        dist[i] = INF;
    }

    dist[src] = 0;
    for(int i=1;i<=v;i++){
        int u = vec[i].u;
        int v = vec[i].v;
        int wt = vec[i].wt;
        if(dist[u] != INF && dist[u] + wt < dist[v]){
            dist[v] = dist[u] + wt;
        }
        // for(int j=1;j<=v;j++){
        //     cout<<dist[j]<<" ";
        // }
        // cout<<endl;
    }

    for(int i=1;i<=v;i++){
        cout<<dist[i]<<" ";
    }

    return 0;
}