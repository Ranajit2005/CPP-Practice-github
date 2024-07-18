#include<iostream>
#include<vector>
using namespace std;

    // House are place in circular so we cannot take last and first house together. We cannot robbery in two consicutive house. We havw to find maximum robbery profit. This problem is similar like Maximum sum of non adjacent elements problem.

int calculate(int index,vector<int>& num,vector<int>&dp){
    //We can do the code with more space optimisation
    if(index == 0) return num[0];
    if(index < 0) return 0;
    if(dp[index] != -1) return dp[index];

    int pick_element = num[index] + calculate(index - 2,num,dp);
    int non_pick_element = 0 + calculate(index - 1,num,dp);

    return dp[index] = max(pick_element,non_pick_element);

}

int RobberyValue(int num[],int size){
    vector<int>dp1(size,-1);
    vector<int>dp2(size,-1);
    vector<int> withoutFirstHouse, withoutLastHouse;

    for (int i = 0; i < size; i++){
        if(i != 0) withoutFirstHouse.push_back(num[i]);
        if(i != size - 1) withoutLastHouse.push_back(num[i]);
    }
    
    return max(calculate(size - 1,withoutFirstHouse,dp1),calculate(size - 1,withoutLastHouse,dp2));
}


int main(){
    int n;
    cout<<"Give the size of the array : ";
    cin>>n;

    int num[n];
    for(int i = 0;i<n;i++){
        cin>>num[i];
    }

    int ans = RobberyValue(num,n);

    cout<<"The Maximum robbery profite is : "<<ans<<endl;

    return 0;
}