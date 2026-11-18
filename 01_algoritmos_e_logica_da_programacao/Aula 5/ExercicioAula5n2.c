#include<stdio.h>
#include<math.h>
int main()
{
    int n1, n2;
    float r1;
    printf("Informe o numero de pecas produzidas: ");
    scanf("%d", &n1);
    printf("Informe o numero de pecas defeituosas: ");
    scanf("%d", &n2);
    r1=(n1*0.1);
    if (n2>=r1){
        printf("A maquina precisa de manutencao!");
    }
    else{
        printf("A producao pode continuar!");
    }
}