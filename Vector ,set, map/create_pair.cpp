#include<iostream>
using namespace std;

template<class t1,class t2>
class Pair{
public:
    t1 first;
    t2 secomd;
};

int main(){
    Pair<int,int>arr[3];
    arr[0].first = 1;
    arr[0].secomd = 10;

    arr[1].first = 0;
    arr[1].secomd = 20;

    arr[2].first = 3;
    arr[2].secomd = 3;
    // for(int i=0;i<10;i++){
    //     arr[i].first = i;
    //     arr[i].secomd = i + 10;
    // }
    int n = 3;
    for(int i = 0 ;i<n-1;i++){
        for(int j = 0;j<n-1-i;j++){
            if(arr[j].first>arr[j+1].first){
                swap(arr[j],arr[j+1]);
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i].first<<" "<<arr[i].secomd<<endl;
    }
    return 0;
}