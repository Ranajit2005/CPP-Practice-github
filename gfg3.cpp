#include<iostream>
using namespace std;

int low(int n,int arr[],int terget){
    int li=0,ans=-1;
    int hi=n-1;
    while(li<=hi){
        int mid=(hi+li)/2;
        if(arr[mid]>=terget){
            ans = mid;
            hi = mid -1;
        }else{
            li = mid +1;
        }
    }
    return ans;
}

int high(int n,int arr[],int terget){
    int li=0,ans=-1;
    int hi=n-1;
    while(li<=hi){
        int mid=(hi+li)/2;
        if(arr[mid]>=terget){
           ans = mid;
            li = mid + 1;
        }else{
            
            hi = mid - 1;
            ans = mid;
        }
    }
    return ans;
}

int main(){
    int arr[]={1,2,3,4,5,5,5,5,5};
    int x = 9;
    int n;
    cin>>n;
    cout<<low(x ,arr,n)<<endl;
    cout<<high(x,arr,n);

return 0;
}