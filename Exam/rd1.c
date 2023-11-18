#include <stdio.h>
int main(){
    int n;
    printf("Enter the number of rows: ");
    scanf("%d",&n);
    int a=65;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            // int d = a + 64;
            printf("%c",a);
            a++;
        }
        printf("\n");
    }
    return 0;
}