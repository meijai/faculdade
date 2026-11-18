#include<stdio.h>
int main()
{
    int ano, idade;
    printf("Digite seu ano de nascimento: ");
    if (scanf("%d", &ano) != 1){
        printf("Dados de entrada invalidos!\n");
        return 1;
    }
    idade=2025-ano;
    if(idade>=18){
        printf("Voce tem %d anos e ja pode votar e ter habilitacao!\n", idade);
    }
    else if (idade>=16 && idade<=17){
        printf("Voce tem %d anos e ja pode votar, porem nao pode ter habilitacao!\n", idade);
    }
    else if (idade<16){
        printf("Voce tem %d anos e nao pode votar nem ter habilitacao!\n", idade);
    }
    return 0;
}