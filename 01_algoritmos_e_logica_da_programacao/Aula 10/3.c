#include<stdio.h>
int main()
{
    int conta=0;
    float saldo=0;
    float negativo=0;
    float total=0;
    float porc=0;
    do{
        printf("Informe o numero da conta (0 para sair): ");
        scanf("%d", &conta);
        printf("Informe o saldo: ");
        scanf("%f", &saldo);
        if(saldo<0){
            negativo++;
        }
        printf("Numero da conta: %d\n", conta);
        printf("Saldo da conta: %.2f\n", saldo);
        if(saldo>=0){
            printf("Saldo positivo.\n");
        }
        else if(saldo<0){
            printf("Saldo negativo.\n");
        }
    }
    while(conta>=0);
    total++;
    porc=negativo*100/total;
    printf("Negativos: %.2f", porc);
}