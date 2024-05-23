#include<iostream>
using namespace std;

void FindMaxMin(int arr[],int low,int high,int *max,int *min){
    if(low == high){
        *max = *min = arr[low];
    }else if(low == high+1){
        if(arr[low] > arr[high]){
            *max = arr[low];
            *min = arr[high];
        }else{
            *max = arr[high];
            *min = arr[low];
        }
    }else{
        int leftMax, leftMin, rightMax, rightMin, mid=(low+high)/2;
        FindMaxMin(arr,low,mid,&leftMax,&leftMin);
        FindMaxMin(arr,mid+1,high,&rightMax,&rightMin);
        if(leftMax<rightMax){
            *max = rightMax;
        }else{
            *max = leftMax;
        }
        if(leftMin<rightMin){
            *min = leftMin;
        }else{
            *min = rightMin;
        }
    }

    return;
}

int main(){
    int n,max,min;
    cout<<"Give the size of the element : ";
    cin>>n;

    int arr[n];
    
    cout<<"Give the element : ";
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    FindMaxMin(arr,0,n-1,&max,&min);
    cout<<"The max element is : "<<max<<endl<<"The minimun element is : "<<min<<endl;
    return 0;
}