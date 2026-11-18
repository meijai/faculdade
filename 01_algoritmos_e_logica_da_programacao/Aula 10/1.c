#include<stdio.h>
int main()
{
    int x=0;
    int num;
    do{
        printf("Informe 1 numero inteiro: ");
        scanf("%d", &num);
        if(num>=100 && num<=200){
            x++;
        }
    }while(num!=0);
    printf("A quantidade de vezes que numeros entre 100 e 200 apareceram foi de %d vezes!\n", x);
}