#include<iostream>
using namespace std;

void TOH(int start,int end,char sour,char help,char dest){
    if(start>end){
        return;
    }else{
        TOH(start,end-1,sour,dest,help);
        cout<<"move "<<end<<" from "<<sour<<" to "<<dest<<endl;
        TOH(start,end-1,help,sour,dest);
    //     count++;
    //     cout<<"Moving "<<count<<endl;
    }
}

int main(){
    TOH(1,5,'A','B','C');
    return 0;
}