#include<stdio.h>
int main()
{
    int idade;
    int novo=0;
    int velho=0;
    do{
        printf("Informe a idade (0 para sair): ");
        scanf("%d", &idade);
        if(idade<=21 && idade!=0){
            novo++;
        }
        else if(idade>=50){
            velho++;
        }
    }while(idade!=0);
    printf("Maiores de 50 anos: %d\n", velho);
    printf("Menores de 21 anos: %d\n", novo);
}