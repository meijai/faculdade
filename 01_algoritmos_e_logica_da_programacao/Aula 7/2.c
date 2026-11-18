#include<stdio.h>
#include<conio.h>
int main()
{
    int x,y,z;
    printf("Digite um numero para mostrar sua tabuada.\n");
    scanf("%d", &x);
    y=0;
    while (y<=10){
        z=x*y;
        printf("%d x %d = %d.\n", x, y, z);
        y++;
    }
}