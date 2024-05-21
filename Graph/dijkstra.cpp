#include<iostream>
using namespace std;

template<class t1 = int,class t3 = int>
class Pair{
public:
    t1 weight;
    t3 vertex;
};

template<class t2 = int>
class vector{
    int* array;
    int capacity;
    int index;
public:
    vector(int n = 0){
        array = (t2*)malloc(n * (sizeof(t2)));
        capacity = n;
        index = 0;
    }

    void push_back(int val){
        capacity ++;
        if(index + 1 == capacity){
            array = (t2*)realloc(array,sizeof(t2) * (capacity + 1));
        }
        array[index++] = val;
    }

    int size(){
        return capacity;
    }

    t2 operator[](int it){
        if(it < 0 || it > capacity - 1) exit(0);
        return array[it];
    }

};

int main(){

    int v,e;
    cout<<"Enter the number of vertices : ";
    cin>>v;
    cout<<"Enter the number of edges : ";
    cin>>e;

    vector<Pair<int,int>>vec[50];
    for(int i=0;i<e;i++){
        int a,b,wt;
        cout<<"Enter which vertices are connected and its weight : ";
        cin>>a>>b>>wt;
        vec[a].push_back(b);
        // vec[b].push_back(a);
        // vec[a][b].weight = wt;
    }

    cout<<"The adjacence list is : "<<endl;

    // for(int i=1;i<=v;i++){
    //     for(int j=0;j<vec[i].size();j++){
    //         cout<<vec[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}