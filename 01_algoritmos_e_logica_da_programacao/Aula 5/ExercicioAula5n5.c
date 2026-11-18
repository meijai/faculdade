// nao fuciona
#include<stdio.h>
int main()
{
    float n1,n2,n3,Maior,Meio,Menor;
    printf("Digite o numero A: ");
    if (scanf("%f", &n1)!=1){
        printf("Valor invalido!\n");
    return 1;
    }
    printf("Digite o numero B: ");
    scanf("%f", &n2);
    printf("Digite o numero C: ");
    scanf("%f", &n3);
    if (n1>=n2 && n1>=n3){
        Maior=n1;
        if (n2>=n3){
            Meio=n2;
            Menor=n3;
        }
        else {
            Menor=n2;
            Meio=n3;
        }
    }
    else if (n2>=n1 && n2>=n3){
        if (n1>=n3){
            Meio=n1;
            Menor=n3;
        }
        else {
            Maior=n3;
            Menor=n1;
            Meio=n3;
        }
    }
    else {
        Maior=n3;
        if (n1>=n2){
            Meio=n1;
            Menor=n2;
        }
        else {
            Menor=n1;
            Meio=n2;
        }
    }
    printf("%.2f Menor\n", Menor);
    printf("%.2f Meio\n", Meio);
    printf("%.2f Maior\n", Maior);
}