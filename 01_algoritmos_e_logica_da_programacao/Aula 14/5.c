#include<stdio.h>
int main()
{
    char nome[5][100];
    int i;
    for(i=0; i<5; i++){
        printf("Informe o nome %d: ", i+1);
        scanf("%s", nome[i]);
    }
    for(i=0; i<5; i++){
        printf("O nome %d e: %s.\n", i+1, nome[i]);
    }
    return 0;
}