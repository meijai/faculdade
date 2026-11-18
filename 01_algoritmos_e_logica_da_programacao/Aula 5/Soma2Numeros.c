#include<stdio.h>
int main()
{
    int x,y,z;
    printf("Digite um numero inteiro: ");
    scanf("%d", &x);
    printf("Digite mais um numero inteiro: ");
    scanf("%d", &y);
    z=x+y;
    printf("O Resultado da soma deu: %d\n", z);
    printf("Pressione enter para sair...");
    getchar();
    getchar();
    return 0;
}