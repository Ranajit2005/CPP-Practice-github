#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>v = {1,2,3,4,5,6,7,8,9};
    vector<int>::iterator it = v.begin();
    cout<<(*it+1);
    

    return 0;
}