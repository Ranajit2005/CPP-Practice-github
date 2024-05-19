#include<iostream>
using namespace std;
//Note : It can be solve using map, pair or sets. Then the code will be more esay.

void OppsiteBubbleSort(int profit[],int deadline[],char job_id[],int n){
    for(int i = 0 ;i<n-1;i++){
        for(int j = 0;j<n-1-i;j++){
            if(profit[j]<profit[j+1]){
                swap(profit[j],profit[j+1]);
                swap(deadline[j],deadline[j+1]);
                swap(job_id[j],job_id[j+1]);
            }
        }
    }
}


int main(){
    int n,max_deadline;
    
    cout<<"Give the number of the Job : ";
    cin>>n;

    int profit[n],deadline [n];
    char job_id[n];

    for(int i=0;i<n;i++){
        cout<<"Give job id as A,B,C... : ";
        cin>>job_id[i];
        cout<<"Give "<<job_id[i]<<" Job Profit and deadline respectivly : ";
        cin>>profit[i]>>deadline[i];
    }

    cout<<"Give the maximum deadline : ";
    cin>>max_deadline;

    OppsiteBubbleSort(profit,deadline,job_id,n);
    for(int i=0;i<n;i++){
        cout<<job_id[i]<<" "<<profit[i]<<" "<<deadline[i]<<endl;
    }


    return 0;
}