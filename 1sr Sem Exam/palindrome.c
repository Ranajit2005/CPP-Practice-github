#include<stdio.h>
int main(){
    int n,r,m=0;
    printf("Enter the number : ");
    scanf("%d",&n);
    int a=n;
    while(n>0){
        r=n%10;
        m=m*10+r;
        n=n/10;
    }
    if(m==a) printf("Palindrome");
    else printf("Not Palindrome");
    return 0;
}