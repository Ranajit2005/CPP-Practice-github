#include<iostream>
#include<vector>
using namespace std;

void MaxHeap(vector<int>vec,int n,int i){
    int largest = i;
    int lchild = 2*i + 1;
    int rchild = 2*i;
    while(lchild<=n && vec[lchild]>vec[i]){
        largest = lchild;
    }
    while(rchild<=n && vec[rchild]>vec[i]){
        largest = rchild;
    }
    if(largest != i){
        swap(vec[i],vec[largest]);
        MaxHeap(vec,n,largest);
    }
}

int main(){
    int n;
    cout<<"Give the size of the vector : ";
    cin>>n;
    int size = n + 1;   //for 1 base index
    vector<int>v(size);
    v[0]=0;
    int element;
    for(int i=1;i<v.size();i++){
        cout<<"Give the element of the array at index "<<i<<" : ";
        cin>>element;
        v[i]=element;
    }
    // MaxHeap(v,v.size(),i);
    for(int i = size/2;i>=1;i--){   //i=size/2 because here we leave node child
        MaxHeap(v,size,i);
    }
    cout<<"After insertion the heap is : ";
    for(int i=1;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}