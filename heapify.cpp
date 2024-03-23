#include<iostream>
#include<vector>
using namespace std;

void MaxHeap(vector<int>&vec,int n,int i){
    int largest = i;
    int lchild = 2*i;
    int rchild = 2*i + 1;
    if(lchild<n && vec[lchild]>vec[largest]){
        largest = lchild;
    }
    if(rchild<n && vec[rchild]>vec[largest]){
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
    cout<<endl;

    //For heap sort
    for(int i=size-1;i>=1;i--){
        swap(v[1],v[i]);
        MaxHeap(v,i,1);
    }

    cout<<"After delete : ";
    for(int i=1;i<v.size();i++){
        cout<<v[i]<<" ";
    }

    return 0;
}