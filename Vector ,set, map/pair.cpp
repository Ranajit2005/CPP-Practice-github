#include<iostream>
using namespace std;

void func(pair<int,string>&q){
    q.first = 7;
}

int main(){
    pair<int,string>p;
    p = {3,"rjd"};
    p.first = 5;
    func(p);
    cout<<p.first<<" "<<p.second<<endl;
    
    pair<int,string>r;
    r = p;
    cout<<r.first<<" "<<r.second<<endl;

    pair<int,int>arr[3];
    arr[0]={1,2};
    arr[1]={3,4};
    arr[2]={5,6};

    for(int i=0;i<3;i++){
        cout<<arr[i].first<<" "<<arr[i].second<<endl;
    }
    
    return 0;
}