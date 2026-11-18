#include<stdio.h>
#include<stdlib.h>
int inverter(int x, int y, int z);
int a,b,c;
int main()
{
    printf("Informe o primeiro valor: ");
    scanf("%d", &a);
    printf("Informe o segundo valor: ");
    scanf("%d", &b);
    inverter(a,b,c=0);
}
int inverter(int x, int y, int z){
    z=x;
    x=y;
    y=z;
    printf("Primeiro valor : %d.\nSegundo valor: %d.", x,y);
    return 0;
}