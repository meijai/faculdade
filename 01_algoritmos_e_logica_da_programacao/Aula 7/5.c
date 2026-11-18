#include<stdio.h>
int main()
{
    int n;
    printf("insira um numero inteiro.\n");
    scanf("%d", &n);
    while(n%2==0) //verifica se o numero informado e par.
    {
        n=n/2;
        printf("%d\n",n);
    }
    while(n%2==1 && n>1) //verifica se o numero e impar.
    {
        n=3*n+1;
        printf("%d\n",n);
    }
}