#include<stdio.h>
#include <string.h>
int main()
{
    char palavra[100];
    int i, comprimento;
    printf("Escreva alguma coisa: ");
    scanf("%s", palavra);
    comprimento = strlen(palavra);
    printf("A palavra em inversa e: ");
    for(i=comprimento-1; i>= 0; i--){
        printf("%c", palavra[i]);
    }
    printf("\n");
    return 0;
}