#include<stdio.h>
int main()
{
    int A,B,C,maior,meio,menor;
    printf("Informe um numero inteiro: ");
    if (scanf("%d", &A)!=1){
        printf("Valor invalido!");
        return 1;
    }
    printf("Informe outro numero inteiro: ");
    if (scanf("%d", &B)!=1){
        printf("Valor invalido!");
        return 1;
    }
    printf("Informe mais um numero inteiro: ");
    if (scanf("%d", &C)!=1){
        printf("Valor invalido!");
        return 1;
    }

    if (A>B && A>C){
        maior=A;
        if (B>C){
            meio=B;
            menor=C;
        }
        else if (C>B){
            meio=C;
            menor=B;
        }
    }
    else if (B>A && B>C){
        maior=B;
        if (A>C){
            meio=A;
            menor=C;
        }
        else{
            meio=C;
            menor=A;
        }
    }
    else{
        maior=C;
        if (A>B){
            meio=A;
            menor=B;
        }
        else{
            meio=B;
            menor=A;
        }
    }
    printf("%d, %d, %d.\n", maior, meio, menor);
}