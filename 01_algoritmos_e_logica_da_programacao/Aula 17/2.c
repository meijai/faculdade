//Alunos Bruno Furlan e Lucas Piva Bellaver.
#include <stdio.h>
#include <stdlib.h>
float multiplicacao (float a, float b){
    float c = a*b;
    return c;
}
float divisao (float x, float y){
    float z = x/y;
    return z;
}
int main()
{
    float n1, n2;
    float resultado;
    int n3;
    printf("Informe o primeiro numero: ");
    scanf("%f", &n1);
    printf("Informe o segundo numero: ");
    scanf("%f", &n2);
    printf("Selecione qual funcao deseja realizar(1 para multiplicacao ou 2 para divisao): ");
    scanf("%d", &n3);
    if(n3==1){
        resultado = multiplicacao(n1, n2);
        printf("O resultado da multiplicacao deu: %.2f.", resultado);
    }
    else if(n3==2){
        resultado = divisao(n1, n2);
        printf("O resultado da divisao deu: %.2f.", resultado);
    }
}