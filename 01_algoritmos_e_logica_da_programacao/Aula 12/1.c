#include<stdio.h>
int main()
{
    int i, j;
    int A[3][3], B[3][3], R[3][3];
    for (i=0; i<3; i++){
        for (j=0; j<3; j++){
            printf("Informe o elemento A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    for (i=0; i<3; i++){
        for (j=0; j<3; j++){
            printf("Informe o elemento B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }
    for (i=0; i<3; i++){
        printf("\n");
        for (j=0; j<3; j++){
            R[i][j] = A[i][j] * B[i][j];
            printf("%d ", R[i][j]);
        }
    }
}