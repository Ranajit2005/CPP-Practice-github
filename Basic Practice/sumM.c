#include<stdio.h>
int main(){
    int r,c,a[100][100],b[100][100],sum[100][100];
    printf("Enter the number of rows : ");
    scanf("%d",&r);
    printf("Enter the number of column : ");
    scanf("%d",&c);
    printf("Enter the 1st matrix");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the 2st matrix");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&b[i][j]);
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            sum[i][j]=a[i][j]+b[i][j];
            printf("%d ", sum[i][j]);
        }
    printf("\n");
    }
    return 0;
}