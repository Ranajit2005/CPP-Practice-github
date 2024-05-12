#include<iostream>
using namespace std;
#define MAX 999

int main(){
    int m;
    cout<<"Give the total number of the matrix : ";
    cin>>m;

    int n = m+1;    //because if No of matrix is n then dimention No is (n+1);
    int dimention[n];
    cout<<"Give the demention respectively ";
    for(int i=0;i<n;i++){
        cin>>dimention[i];
    }

    int cost[n][n] = {0};
    int k_value[n][n] = {0};

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cost[i][j] = 0;
            k_value[i][j] = 0;
        }
    }

    for(int d=1;d<n-1;d++){
        for(int i=1;i<n-d;i++){

            int j = i+d;
            int min = MAX;

            for(int k=i;k<j;k++){
                int val = cost[i][k] + cost[k+1][j] + dimention[i-1] * dimention[k] * dimention[j];

                if(val < min){
                    min = val;
                    k_value[i][j] = k;
                }
                cost[i][j] = min;
            }
        }
    }

    cout<<"The minimun number of multiplication is : "<<cost[1][n-1];

    return 0;
}

    // int arr[2*n];
    // for(int i=0;i<n;i++){
    //     cout<<"Give the dimention of "<<i + 1<<" matrix :";
    //     cin>>arr[2*i]>>arr[2*i+1];
    // }

    // int dimention[n+1];

    // for(int i=1;i<2*n;i+2){
    //     if(arr[i] != arr[i+1]){
    //         cout<<"Multiplication cannot be possible "<<endl;
    //     }
    // }

    // for(int i=0;i<2*n;i++){
    //     cout<<arr[i]<<" ";
    // }