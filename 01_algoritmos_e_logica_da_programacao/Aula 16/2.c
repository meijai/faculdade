#include<stdio.h>
#include<stdlib.h>
float a,b,c;
void dobro(float x, float y, float z);
main()
{
    printf("Informe um valor: ");
    scanf("%f", &a);
    printf("Informe outro valor: ");
    scanf("%f", &b);
    printf("Informe mais um valor: ");
    scanf("%f", &c);
    dobro (a,b,c);
}
void dobro(float x,float y,float z){
    x=x*2;
    y=y*2;
    z=z*2;
    printf("%.2f %.2f %.2f", x,y,z);
}