#include<stdio.h>
int main()
{
    int x,y;
    printf("Digite um numero:");
    scanf("%d",&x);
    y=x%2;
    if(y==0)
    {
        printf("O numero %d e par.\n", x);
    }
    else
    {
        printf("O numero %d e impar.\n", x);
    }
    printf("Pressione enter para sair...");
    getchar();
    getchar();
    return 0;
}