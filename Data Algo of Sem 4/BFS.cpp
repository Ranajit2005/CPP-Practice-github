#include<iostream>
#include<fstream>
using namespace std;

const int N = 100;
int graph[N][N];
bool visited[N] = {0};

class Q{
public:
    int arr[100];
    int rear;
    int front;
    Q(){
        rear = -1;
        front = -1;
    }
    void push(int val){
        rear ++;
        arr[rear] = val;
    }

    int pop(){
        front++;
        return arr[front];
    }

    bool empty(){
        if(rear == front)   return 1;
        return 0;
    }

    void show(){
        for(int i = front+1;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
    }
};

// Q q;

void BFS(int src,int v){
    Q q;
    // cout<<src<<" ";
    q.push(src);
    visited[src]=1;
    while(!q.empty()){
        int cur = q.pop();
        cout<<cur<<" ";
        for(int i=0;i<v;i++){
            if(graph[cur][i] == 1 && !visited[i]){
                q.push(i);
                visited[i] = 1;
            } 
        }
    }
}

int main(){
    int v,e;
    fstream infile;
    infile.open("GraphRead.txt",ios::in);
    infile>>v>>e;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            infile>>graph[i][j];
        }
    }
    // Q q;
    BFS(1,v);
    
    return 0;
}