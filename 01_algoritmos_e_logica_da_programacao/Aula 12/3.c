#include<stdio.h>
int main()
{
    int i, j, A[3][4], B[3][4];
    for(i=0; i<3; i++){
        for(j=0; j<4; j++){
            printf("Informe o elemento A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    for(i=0; i<3; i++){
        printf("\n");
        for(j=0; j<4; j++){
            B[i][j]= A[i][j]*3;
            printf("%d ", B[i][j]);
        }
    }
}