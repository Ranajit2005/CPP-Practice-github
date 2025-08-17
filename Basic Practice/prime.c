#include<stdio.h>
int main(){
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);
    if(n==1 || n==0) printf("Not prime");
    for(int i=2;i<=n/2;i++){
        if(n%i==0){
            printf("Not prime");
            break;
        }
        else printf("Prime");
    }
    return 0;
}