#include<iostream>
#include<vector>
using namespace std;

    // Maximum sum of non adjacent elements

int calculate(int index,int num[],vector<int>&dp){
    if(index == 0) return num[0];
    if(index < 0) return 0;
    if(dp[index] != -1) return dp[index];

    int pick_element = num[index] + calculate(index - 2,num,dp);
    int non_pick_element = 0 + calculate(index - 1,num,dp);

    return dp[index] = max(pick_element,non_pick_element);

}

int maxSum(int num[],int size){
    vector<int>dp(size,-1);
    return calculate(size - 1,num,dp);
}


int main(){
    int n;
    cout<<"Give the size of the array : ";
    cin>>n;

    int num[n];
    for(int i = 0;i<n;i++){
        cin>>num[i];
    }

    int ans = maxSum(num,n);

    cout<<"The Maximum sum of non adjacent elements is : "<<ans<<endl;

    return 0;
}