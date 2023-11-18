#include<stdio.h>
int main(){
    int a;
    printf("1st valirable : ");
    scanf("%d",&a);
    int b;
    printf("2nd valirable : ");
    scanf("%d",&b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("%d\n",a);
    printf("%d",b);
    return 0;
}