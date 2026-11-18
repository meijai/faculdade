#include<stdio.h>
int main()
{
    int consumidor=1, tipo;
    float total_res=0, total_com=0, total_ind=0;
    float res, com, ind;
    int num_res=0;
    int num_com=0;
    float media_res;
    float media_com;
    float custo_res, custo_com, custo_ind;

    while (1){
        //pergunta qual o tipo de consumidor, se 0 quebra o ciclo
        printf ("Informe o numero do consumidor (0 para sair): ");
        scanf("%d", &consumidor);
        if (consumidor == 0){
            break;
        }
        else if (consumidor<0 || consumidor>3){
            printf("consumidor invalido.\n");
            return 1;
        }
        //escolhe o tipo de consumidor
        printf("Informe o tipo de consumidor (1=residencial, 2=comercial, 3=industrial): ");
        scanf("%d", &tipo);
        if(tipo==1){ //soma tipo residencial
            printf("Informe o consumo do tipo residencial: ");
            scanf("%f", &res);
            total_res+=res;
            num_res++;
        }
        else if(tipo==2){ //soma tipo comercial
            printf("Informe o consumo do tipo comercial: ");
            scanf("%f", &com);
            total_com+=com;
            num_com++;
        }
        else if(tipo==3){ //soma tipo industrial
            printf("Informe o consumo do tipo industrial: ");
            scanf("%f", &ind);
            total_ind+=ind;
        }
    }
    media_res=total_res/num_res;
    media_com=total_com/num_com;
    custo_res=total_res*0.3;
    custo_com=total_com*0.5;
    custo_ind=total_ind*0.7;

    printf("Consumo total de %.3f kWh do tipo residencial.\n", total_res); // total consumo residencial
    printf("Custo total de %.2f reais para o tipo residencial.\n", custo_res); // custo total residencial
    printf("Consumo total de %.3f kWh do tipo comercial.\n", total_com); // total consumo comercial
    printf("Custo total de %.2f reais para o tipo comercial.\n", custo_com); // custo total comercial
    printf("Consumo total de %.3f kWh do tipo industrial.\n", total_ind); // total consumo industrial
    printf("Custo total de %.2f reais para o tipo industrial.\n", custo_ind); // custo total industrial

    if(num_res>0){ // media de consumo residencial
    printf("Media de consumo de %.3f kWh entre %d consumidores do tipo residencial.\n", media_res, num_res);
    }
    if(num_com>0){ // media de consumo comercial
    printf("Media de consumo de %.3f kWh entre %d consumidores do tipo comercial.\n", media_com, num_com);
    }
}