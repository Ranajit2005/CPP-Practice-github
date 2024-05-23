#include<iostream>
using namespace std;

void OppsiteBubbleSort(float p_w[],float profit[],float weight[],int n){
    for(int i = 0 ;i<n-1;i++){
        for(int j = 0;j<n-1-i;j++){
            if(p_w[j]<p_w[j+1]){
                swap(p_w[j],p_w[j+1]);
                swap(profit[j],profit[j+1]);
                swap(weight[j],weight[j+1]);
            }
        }
    }
}

int main(){

    int n,maxwt;
    cout<<"Give the number of the item : ";
    cin>>n;

    float profit[n],weight[n],p_w[n];
    for(int i = 0;i<n;i++){
        cout<<"Give the profite and weigth of "<<i+1<<"th item repectivly : ";
        cin>>profit[i]>>weight[i];
    }

    cout<<"Give the maximum weight that can be taken : ";
    cin>>maxwt;

    for(int i = 0;i<n;i++){
        p_w[i] = profit[i] / weight[i];
    }

    OppsiteBubbleSort(p_w,profit,weight,n);

    float wt_bag = 0,final_profit = 0;

    for(int i=0;i<n;i++){
        if(wt_bag + weight[i] <= maxwt){
            wt_bag += weight[i];
            final_profit += profit[i];
        }else{
            float remaining_wt = maxwt - wt_bag;
            final_profit += (profit[i]/weight[i])*remaining_wt;
            break;
        }
    }

    cout<<"The maximun profit is : "<<final_profit<<endl;

    return 0;
}