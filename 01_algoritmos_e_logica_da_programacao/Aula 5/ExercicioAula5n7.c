#include<stdio.h>
int main ()
{
    int a, b, c;
    printf("Informe o primeiro numero: ");
    if (scanf("%d", &a)!=1){
        printf("Valor invalido.\n");
        return 1;
    }
    printf("Informe o segundo numero: ");
    if (scanf("%d", &b)!=1){
        printf("Valor invalido.\n");
        return 1;
    }
    printf("Informe o terceiro numero: ");
    if (scanf("%d", &c)!=1){
        printf("Valor invalido.\n");
        return 1;
    }
    if (a>=b && a>=c)
    {
        if (a>b && a>c){
            printf("O maior numero e o %d.\n", a);
            
        }
        else if (a==b && a==c){
            printf("Todos os numeros sao iguais.\n");
        }
        else if (a==b){
            printf("Os maiores numeros sao %d e %d.\n", a, b);
        }
        else if (a==c){
            printf("Os maiores numeros sao %d e %d.\n", a, c);
        }
    }
    else if (b>=a && b>=c)
    {
        if (b>a && b>c){
            printf("O maior numero e o %d.\n", b);
        }
        else if (b==c){
            printf("Os maiores numeros sao %d e %d.\n", b, c);
        }
    }
    else if (c>=a && c>=b)
    {
        if (c>a && c>b){
            printf("O maior numero e o %d.\n", c);
        }
    }
    return 0;
}