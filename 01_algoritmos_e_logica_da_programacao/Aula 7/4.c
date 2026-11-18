#include<stdio.h>
int main()
{
    int dias;
    int mes;
    printf("Insira um mes valido de 1 a 12.\n");
    scanf("%d", &mes);
    if (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12){
        dias=31;
        printf("O mes %d possui %d dias.\n", mes,dias);
    }
    else if (mes==4 || mes==6 || mes==9 || mes==11){
        dias=30;
        printf("O mes %d possui %d dias.\n", mes,dias);
    }
    else if (mes==2){
        dias=29;
        printf("O mes %d possui %d dias.\n", mes,dias);
    }
    return 0;
}