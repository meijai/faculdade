#include<stdio.h>
#include<math.h>
int main()
{
    int n1;
    float r1, r2;
    printf("Digite o numero de copias: ");
    scanf("%d", &n1);
    r1=(n1*0.25);
    r2=(n1*0.20);
    if (n1<=100){
        printf("O valor a ser pago e de: %.2f reais.", r1);
    }
    else{
        printf("O valor a ser pago e de: %.2f reais.", r2);
    }
}