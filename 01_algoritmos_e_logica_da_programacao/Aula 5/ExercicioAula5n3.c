#include<stdio.h>
int main()
{
    int n1;
    printf("Insira a idade do profissional: ");
    scanf("%d", &n1);
    if (n1<=10){
        printf("Atleta na categoria Infantil\n");
    }
    else if(n1>10 && n1<=17){
        printf("Atleta na categoria Juvenil\n");
    }
    else{
        printf("Atleta na categoria Senior\n");
    }
}