#include<iostream>
using namespace std;

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void displayAnyPosition(int arr[],int n,int pos){
    if(pos>=1 && pos<=n){
                cout<<"the element of position "<<pos<<" is "<<arr[pos-1];
            }
            else{
                cout<<"invalid position ";
            }
            cout<<endl;
}
void updatePos(int arr[],int n,int pos,int val){
    if(pos>=1 && pos<=n){
        arr[pos-1]=val;
        cout<<"the value of pos "<<pos<<" is updated with "<<val<<endl;
    }
    else{
        cout<<"invalid position "<<endl;
    }
}
void insert(int arr[],int n,int pos,int val){
    if(n<100 && pos>=1 && pos<=n+1){
        for(int i=n;i>=pos;i--){
            arr[i]=arr[i-1];
        }
        arr[pos-1]=val;
        n++;
        display(arr,n);
    }
}
void remove(int arr[],int n,int val){
    for(int i=0;i<n;i++){
        if(arr[i]==val){
            for(int j=i;j<n-1;j++){
                arr[j]=arr[j+1];
            }
            n--;
            display(arr,n);
            return;
        }
    }
}
void search(int arr[],int n,int val){
    for(int i=0;i<n;i++){
        if(arr[i]==val){
            cout<<val<<" is present in array ";
        }
    }
}

int main(){
    int n,choice,pos,val;
    cout<<"enter length of array ";
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
        cout<<i+1<<" element ";
        cin>>arr[i];
    }
    do{
    cout<<endl;
    cout<<"ARRAY-OPERATION\n1.display array elements \n2. display any element\n3. update arrayPos\n4. insert in array\n5. searching\n6. removing\n0. exit\n";
    cout<<"enter operation you want to perform ";
    cin>>choice;
    switch(choice){
        case 1:
            display(arr,n);
            break;
        case 2:
            cout<<"enter the position ";
            cin>>pos;
            displayAnyPosition(arr,n,pos);
            display(arr,n);
            break;
        case 3:
            cout<<"enter the position ";
            cin>>pos;
            cout<<"enter the val ";
            cin>>val;
            updatePos(arr,n,pos,val);
            display(arr,n);
            break;
        case 4:
            cout<<"enter the position ";
            cin>>pos;
            cout<<"enter the val ";
            cin>>val;
            insert(arr,n,pos,val);
            break;
        case 5:
            cout<<"enter element to search ";
            cin>>val;
            search(arr,n,val);
            display(arr,n);
        case 6:
            cout<<"enter element to search ";
            cin>>val;
            remove(arr,n,val);
            break;  
        case 0:
            cout<<"exit from this code ";
            break;
        default :
            cout<<"invalid inputs ";
            break;
        }
    }while(choice);
}