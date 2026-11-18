#include<stdio.h>
int main()
{
    int idade, velho, i, x;
    printf("Quantos idosos ha na clinica?\n");
    if (scanf("%d", &x)!=1){
        printf("valor invalido.\n");
        return 1;
    }
    printf("Qual e a idade do idoso numero 1?\n");
    scanf("%d", &velho);

    for (i=2; i<=x; i++){
        printf("Qual a idade do idoso numero %d?\n", i);
        scanf("%d", &idade);

        if(idade > velho){
            velho = idade;
        }
    }
    printf("O idoso mais veio tem %d.\n", velho);
}