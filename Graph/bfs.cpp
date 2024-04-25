#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 100;
int visited[100] = {0};
vector<int>graph[N];
int level[N];

void BFS(int src){
    queue<int>q;
    q.push(src);    //take the 1st element and put in the queue
    visited[src] = 1;   //marked it as visited

    while(!q.empty()){
        int cur_v = q.front();  //take the access 1st element of the queue
        q.pop();    //and pop this element
        cout<<cur_v<<" ";   //here we print the BFS order

        for(int child : graph[cur_v]){  //run for all the g[i] element 
            if(!visited[child]){    //if this is not visited
                q.push(child);
                visited[child] = 1;
            }
        }
    }
    cout<<endl;
}

int main(){
    int e,a;
    cout<<"Give the edges number : ";
    cin>>e;

    for(int i = 0;i <e ;i++){
        int v1,v2;
        cout<<"Which two vertices are connected : ";
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    cout<<"From which vertices you want to start bfs : ";
    cin>>a;
    BFS(a);

    return 0;
}