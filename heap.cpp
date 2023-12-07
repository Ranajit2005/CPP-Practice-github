#include<iostream>
using namespace std;

void InsertForMaxHeap(int arr[],int n){
    int temp,i=n;
    temp = arr[n];
    while(i>1 && temp>arr[i/2]){
        arr[i] = arr[i/2];
        i = i/2;
    }
    arr[i] = temp;
}

void InsertForMinHeap(int arr[],int n){
    int temp,i=n;
    temp = arr[n];
    while(i>1 && temp<arr[i/2]){
        arr[i] = arr[i/2];
        i = i/2;
    }
    arr[i] = temp;
}
	
	// void heapify(int i,int n){
	// 	int largest = i;
	// 	int left = 2*i , right = left + 1;
	// 	if( left < n && v[left] > v[largest] )  largest = left;
	// 	if( right < n && v[right] > v[largest] )  largest = right;
	// 	if( largest != i ){
	// 		swap( v[largest] , v[i] );
	// 		heapify( largest , n );	
	// 	}

void Delete(int arr[],int n){   //Delete is possible only from rrot
    int x,i,j;
    x = arr[1];     //store root at a variable
    arr[1] = arr[n];    //Delete root
    i = 1;
    j = 2 * i;
    while(j<=n-1){
        if(arr[j+1]>arr[j]){    //Check which is bigger bigger between left or right child
        j = j+1;   
        }
        if(arr[i]<arr[j]){      //Check whichn is bigger between parent and child
            swap(arr[i],arr[j]);
            i=j;
            j=2*i;
        }
        else    break;
    }
    arr[n] = x;
}

int main(){
    int n;
    cout<<"Give the size of the array : ";
    cin>>n;
    int size = n + 1;   //for 1 base index
    int arr[size];
    arr[0]=0;   //because here we don't use index 0
    for(int i=1;i<size;i++){    //start from index 1
        cout<<"Give the element of the array at index "<<i<<" : ";
        cin>>arr[i];
        InsertForMaxHeap(arr,i);
        // InsertForMinHeap(arr,i);
        // cout<<endl;
    }

    cout<<"After insert the array is : ";
    for(int i=1;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    // for(int i=size-1;i>2;i--){
    //     Delete(arr,i);
    // }
    Delete(arr,5);
    Delete(arr,4);
    Delete(arr,3);
    // // Delete(arr,2);
    // // Delete(arr,1);
    cout<<"The sorted array is : ";
    for(int i=1;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}