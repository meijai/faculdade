#include<stdio.h>
int main ()
{
    char palavra[100];
    int contador=0;
    int i;
    printf("Escreva alguma palavra aleatoria: ");
    scanf("%s", palavra);
    for(i=0; i<strlen(palavra); i++){
        if(palavra[i]=='a' || palavra[i]=='e' || palavra[i]=='i' || palavra[i]=='o' || palavra[i]=='u'
        || palavra[i]=='A' || palavra[i]=='E' || palavra[i]=='I' || palavra[i]=='O' || palavra[i]=='U'){
            contador++;
        }
    }
    printf("O numero de vogais na sua palavra e de: %i.\n", contador);
    return 0;
}