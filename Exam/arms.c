#include<stdio.h>
int main(){
    int n,r,sum=0;
    printf("Enter the number :");
    scanf("%d",&n);
    int a=n;
    while(n>0){
        r=n%10;
        sum=sum+(r*r*r);
        n=n/10;
    }
    if(sum==a) printf("Armstrong Number");
    else printf("Not Armstrong Number");
    return 0;
}