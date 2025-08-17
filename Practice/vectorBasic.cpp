#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v(3);
    cout<<"Size :"<<v.size()<<endl;
    cout<<"Capacity :"<<v.capacity()<<endl;

    // v.push_back(3);
    // cout<<"Size :"<<v.size()<<endl;
    // cout<<"Capacity :"<<v.capacity()<<endl;

    // v.push_back(3);
    // cout<<"Size :"<<v.size()<<endl;
    // cout<<"Capacity :"<<v.capacity()<<endl;

    // v.push_back(3);
    // cout<<"Size :"<<v.size()<<endl;
    // cout<<"Capacity :"<<v.capacity()<<endl;

    // v.push_back(3);
    // cout<<"Size :"<<v.size()<<endl;
    // cout<<"Capacity :"<<v.capacity()<<endl;

    // v.push_back(3);
    // cout<<"Size :"<<v.size()<<endl;
    // cout<<"Capacity :"<<v.capacity()<<endl;
    
    /*take input in vector*/

    int element;
    for(int i=0;i<5;i++){
        cin>>element;
        v.push_back(element);
    }

    v.insert(v.begin()+1,9);
    v.erase(v.end()-2);

    cout<<"Size :"<<v.size()<<endl;

    //print output

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    
    return 0;
}