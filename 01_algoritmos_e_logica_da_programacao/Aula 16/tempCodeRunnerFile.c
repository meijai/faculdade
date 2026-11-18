#include<stdio.h>
#include<stdlib.h>
void dobro(int x, int y, int z){
    x++;
    y++;
    z++;
    printf("%f %f %f", x,y,z);
}
main ()
float a,b,c;
{
    printf("Informe um valor: ");
    scanf("%f", &a);
    printf("Informe outro valor: ");
    scanf("%f", &b);
    printf("Informe mais um valor: ");
    scanf("%f", &c);
    dobro (a,b,c);
}