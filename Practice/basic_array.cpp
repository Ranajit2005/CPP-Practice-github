#include<iostream>
using namespace std;

int main(){
    int arr[]={1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<sizeof(arr)<<"\n";
    cout<<"Size of the array is "<<sizeof(arr)/sizeof(arr[0])<<endl;
    cout<<arr[0]<<endl;
    // /*Print Array*/

    /*Nother ahrray input*/
    
    int a;
    cin>>a;
    char vowels[a];
    /*for loop*/
    for(int i=0;i<a;i++){
        cin>>vowels[i];
    }
    for(int i=0;i<a;i++){
        cout<<vowels[i];
    }

    /*for each loop*/
    int s;
    cin>>s;
    char vowels[s];
    
    for(char &ele:vowels){ //when wew take input , we use and oparetor
        cin>>ele;
    }
    for(char ind:vowels){ // variable type and arr type should same
        cout<<ind<<" ";
    }cout<<endl;
    return 0;
}