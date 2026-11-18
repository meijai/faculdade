#include<stdio.h>
#include<math.h>
int main()
{
    float x,y,z;
    printf("Informe seu peso:");
    scanf("%f", &x);
    printf("Informe sua altura:");
    scanf("%f", &y);
    z=x/pow(y,2);
    printf("Seu IMC e de %f\n", z);
    printf("Pressione enter para sair...");
    getchar();
    getchar();
    return 0;
}