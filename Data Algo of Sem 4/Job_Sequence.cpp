#include<iostream>
using namespace std;

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
    cout<<"Give the number of the job : ";
    cin>>n;

    int profit[n],deadline[n];
    char job_id[n];

    for(int i=0;i<n;i++){
        cout<<"Give job id as A,B,C ... : ";
        cin>>job_id[i];
        cout<<"Give the profit and deadline : ";
        cin>>profit[i]>>deadline[i];
    }

    cout<<"Give the maximum deadline : ";
    cin>>max_deadline;

    OppsiteBubbleSort(profit,deadline,job_id,n);

    char slot[max_deadline+1];  
    for(int i=0;i<=max_deadline;i++){
        slot[i] = '.';
    }

    int count_job=0,final_profit = 0;

    for(int i=0;i<n;i++){
        for(int j=deadline[i];j>0;j--){
            if(slot[j] == '.'){
                slot[j] = job_id[i];
                count_job++;
                final_profit += profit[i];
                break;
            }
        }
    }

    cout<<"The maximum profit is : "<<final_profit<<endl<<"Total job can be performed : "<<count_job<<endl<<"The slot is : ";

    for(int i=1;i<=max_deadline;i++){
        cout<<slot[i]<<" ";
    }

    return 0;
}