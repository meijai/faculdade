//Alunos Bruno Furlan e Lucas Piva Bellaver.
#include<stdio.h>
#include<stdlib.h>
int SuperSomador(int a, int b);
int main()
{
    int n1, n2;
    int resultado;
    printf("Informe o primeiro numero: ");
    scanf("%d", &n1);
    printf("Informe o segundo numero: ");
    scanf("%d", &n2);
    resultado = SuperSomador(n1, n2);
    printf("Resultado da soma: %d\n", resultado);
}
int SuperSomador(int a, int b){
    int soma = 0;
    int c, i;
    if( a > b){
        c=a;
        a=b;
        b=c;
    }
    for(i=a; i<=b; i++){
        soma += i;
    }
    return soma;
}
