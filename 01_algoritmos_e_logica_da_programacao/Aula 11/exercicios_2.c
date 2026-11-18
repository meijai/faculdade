#include<stdio.h>
int main()
{
    int n[10], i=1, posicao;
    float n1, menor=10000;
    for(i; i<11; i++){
        printf("Informe o valor n. %d: ", i);
        scanf("%f", &n1);
        if(n1<menor){
            menor=n1;
            posicao=i;
        }
    }
    printf("O menor numero informado e: %.2f\n", menor);
    printf("O menor numero encontra-se na posicao n. %d", posicao);
}