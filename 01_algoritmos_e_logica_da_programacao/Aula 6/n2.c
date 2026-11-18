#include<stdio.h>
int main()
{
    int i, x;
    float nota, media;
    printf("Informe a quantidade de alunos: ");
    if (scanf("%d", &x)!=1){
        printf("Valor invalido!\n");
        return 1;
    }
    for(i=1; i<=x; i++){
        printf("Digite a nota do aluno %d.\n", i);
        scanf("%f", &nota);
        media+=nota;
    }
    media=media/x;
    printf("A media da turma e: %.2f.\n", media);
}