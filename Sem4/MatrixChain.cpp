#include<iostream>
using namespace std;
#define INF 9999

int main(){
    int m;
    cout<<"Give the number of the Matrix : ";
    cin>>m;

    int n = m+1;
    int diamention[n];

    for(int i = 0;i<n;i++){
        cout<<"Give the diemention : ";
        cin>>diamention[i];
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
            int min = INF;

            for(int k=i;k<j;k++){
                int val = cost[i][k] + cost[k+1][j] + diamention[i-1] * diamention[k] * diamention[j];

                if(val<min){
                    min = val;
                    k_value[i][j] = k;
                }
                cost[i][j] = min;
            }
        }
    }

    cout<<"The cost of the matrix is : ";

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<cost[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"The minimun number of multiplication is : "<<cost[1][n-1];

    return 0;
}