#include<stdio.h>
int main()
{
    float x,y;
    printf("Informe o valor total de vendas:");
    scanf("%f", &x);
    y=x*0.1;
    printf("A comissao e de: %f reais\n", y);
    printf("Pressione enter para sair...");
    getchar();
    getchar();
    return 0;
}