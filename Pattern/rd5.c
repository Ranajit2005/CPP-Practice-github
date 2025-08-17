#include<stdio.h>
int main(){
    int n;
    printf("enter the number of rows: ");
    scanf("%d",&n);
    int a=1;

    for(int i=1;i<=n;i++){
        for(int k=1;k<=n-i;k++){
            printf(" ");
        }
        for(int j=1;j<=i;j++){
            printf("%d",a);
            a++;
        }
        for(int m=1;m<i;m++){
            printf("%d",a);
        }
        printf("\n");
    }
    return 0;
}