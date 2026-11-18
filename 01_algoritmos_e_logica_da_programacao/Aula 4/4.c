#include<stdio.h>
int main()
{
    float x,y,z;
    printf("Informe a distancia percorrida:");
    scanf("%f", &x);
    printf("Informe a quantidade de litros de combustivel consumida:");
    scanf("%f", &y);
    z=x/y;
    printf("Seu veiculo fez um total de %f kilometros por litro de media\n", z);
    printf("Pressione enter para sair...");
    getchar();
    getchar();
    return 0;
}