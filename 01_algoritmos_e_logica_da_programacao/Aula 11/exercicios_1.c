#include<stdio.h>
int main()
{
    int n[10], i=1;
    float n1, maior;
    for(i; i<11; i++){
        printf("Informe o valor n. %d: ", i);
        scanf("%f", &n1);
        if(n1>maior){
            maior=n1;
        }
    }
    printf("O maior numero informado e: %.2f\n", maior);
}