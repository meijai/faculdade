#include<stdio.h>
int main()
{
    int x,y,z;
    printf("Informe o comprimento da sala:");
    scanf("%d", &x);
    printf("Informe a largura da sala:");
    scanf("%d", &y);
    z=x*y;
    printf("A sala tem %d metros quadrados\n", z);
    printf("Pressione enter para sair...");
    getchar();
    getchar();
    return 0;
}