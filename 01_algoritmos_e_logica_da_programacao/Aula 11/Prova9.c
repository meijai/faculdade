#include <stdio.h>
int main()
{
    float n1, n2;
    float x,y,z;
    printf("Informe 2 valores: ");
    scanf("%f %f", &n1, &n2);
    x=n1+n2;
    y=n1*(n2*n2);
    z=n1*n1;
    printf("x=%.2f\n", x);
    printf("y=%.2f\n", y);
    printf("z=%.2f\n", z);
}