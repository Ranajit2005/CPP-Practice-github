#include<iostream>
using namespace std;
class linearsearch{

    int i,key,n,*arr[20];
    public:
    int search();
    void input(){
        cout<<"Enter how many values :";
        cin>>n;
        cout<<"Enter values in array :";
        for(i=0;i<n;i++){
            cin>>*arr[i];
        }
        cout<<"Enter a value to find:";
        cin>>key;  
    }
};

int linearsearch :: search(){
    int i,n,*arr[20],key;
    for(i=0;i<n;i++){
        if(*arr[i]==key){
            return 1;
        }else{
            return -1;
        }
    }
}

main(){
    linearsearch ls;
    // ls.input();
    ls.input();
    int index=ls.search();
    if(index==1){
        cout<<"Element is found"<<endl;
    }
    else{
        cout<<"element is not found and its position is"<<endl;
    }
}