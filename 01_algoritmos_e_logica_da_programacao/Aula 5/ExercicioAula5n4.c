#include<stdio.h>
int main()
{
    float n1, n2, n3;
    printf("Digite o valor do lado A: ");
    if (scanf("%f", &n1)!=1){
        printf("Valores invalidos para um triangulo.\n");
        return 1;
    }
    printf("Digite o valor do lado B: ");
    if (scanf("%f", &n2)!=1){
        printf("Valores invalidos para um triangulo.\n");
        return 1;
    }
    printf("Digite o valor do lado C: ");
    if (scanf("%f", &n3)!=1){
        printf("Valores invalidos para um triangulo.\n");
        return 1;
    }
    if (n1+n2>n3 && n1+n3>n2 && n2+n3>n1){
        printf("Estas medidas formam um triangulo.\n");
        if (n1==n2 && n2==n3){
            printf("Este triangulo e Equilatero. \n");
        }
        else if (n1==n2 || n1==n3 || n2==n3){
            printf("Este triangulo e Isosceles. \n");
        }
        else {
            printf("Este triangulo e Escaleno. \n");
        }
    }
    else {
        printf("Valores invalidos para um triangulo\n");
    }
    return 0;
}