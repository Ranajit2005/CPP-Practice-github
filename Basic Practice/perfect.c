#include<stdio.h>
int main(){
    int n,r,sum=0;
    printf("Enter the number : ");
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        r=n%i;
        if(r==0) sum = sum + i;
    }
    if(sum==n || n==1) printf("The number is perfect");
    else printf("The number is not perfect");
    return 0;
}