#include<iostream>
using namespace std;

int equilibriumPoint(long long a[], int n) {
        if(n==1)    return 1;
        long long total = 0;
        long long left = 0;
        for (int i = 0;i < n;i++){
            total = total + a[i];
        }
        total = total / 2;
        int j = 0;
        for(int i = 0;i<n;i++){
            left = left + a[i];
            if(left>=total) break;
            j++;
        }
        return j+1;
    }

int main(){
    long long arr[]={1,1,1,1,1,1,900,2,2,2};
    int n = 10;

    cout<<equilibriumPoint(arr,n);

return 0;
}