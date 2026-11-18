#include<stdio.h>
int main()
{
    int n1;
    printf("Digite um numero inteiro:");
    scanf("%d", &n1);
    n1=n1*2;
    printf("O dobro desse numero e: %d\n", n1);
    printf("Pressione enter para sair...");
    getchar();
    getchar();
    return 0;
}