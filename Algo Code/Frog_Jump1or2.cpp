#include<iostream>
using namespace std;
// Frog can jump at a time for one or two steps

int FromJump(int n,int cost[]){
    int DpArray[n] = {0};
    DpArray[0] = 0;

    for(int i = 1;i<n;i++){
        // jump = previous energy loss + current energy loss
        
        int OneJump = DpArray[i-1] + abs(cost[i] - cost[i-1]);
        int TwoJump = INT16_MAX;
        if(i>1)     TwoJump = DpArray[i-2] + abs(cost[i] - cost[i-2]);

        //Update Dp Array
        DpArray[i] = min(OneJump,TwoJump);
    }

    return DpArray[n-1];

}

int main(){
    int step;
    cout<<"Give the total number of steps : ";
    cin>>step;

    int cost[step];
    for(int i=0;i<step;i++){
        cout<<"Give energy between "<<i<<" and "<<i+1<<"step : ";
        cin>>cost[i];
    }

    int ans = FromJump(step,cost);
    cout<<"The minimum energy required is : "<<ans<<endl;

    return 0;
}