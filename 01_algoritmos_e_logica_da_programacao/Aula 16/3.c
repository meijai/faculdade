#include<stdio.h>
#include<stdlib.h>
float grau(float angulo);
float x;
main()
{
    printf("Informe o angulo: ");
    scanf("%f", &x);
    grau(x);
}
float grau(float angulo)
{
    angulo = (angulo*180)/3.14;
    printf("%.2f", angulo);
}