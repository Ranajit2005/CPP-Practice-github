#include<iostream>
using namespace std;

    // Maximum sum of non adjacent elements

int calculate(int index,int num[]){
    if(index == 0) return num[0];
    if(index < 0) return 0;

    int pick_element = num[index] + calculate(index - 2,num);
    int non_pick_element = 0 + calculate(index - 1,num);

    return max(pick_element,non_pick_element);

}

int maxSum(int num[],int size){
    return calculate(size - 1,num);
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