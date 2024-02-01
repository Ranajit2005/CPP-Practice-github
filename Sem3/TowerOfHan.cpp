#include<iostream>
using namespace std;

void TOH(int start,int end,char sour,char help,char dest){
    if(start>end){
        return;
    }else{
        TOH(start,end-1,sour,dest,help);
        cout<<"move "<<end<<" from "<<sour<<" to "<<dest<<endl;
        TOH(start,end-1,help,sour,dest);
    }
}

int main(){
    TOH(1,3,'A','B','C');
    return 0;
}