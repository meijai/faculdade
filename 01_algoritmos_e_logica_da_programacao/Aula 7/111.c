#include <stdio.h>

int main() {
    int consumidor, tipo;
    float kwh, custo;
    float total_res = 0, total_com = 0, total_ind = 0;
    int count_res = 0, count_com = 0;

    while (1) {
        printf("Informe o numero do consumidor (0 para sair): ");
        scanf("%d", &consumidor);
        
        if (consumidor == 0) {
            break;
        }

        printf("Informe a quantidade de kWh consumidos: ");
        scanf("%f", &kwh);

        printf("Informe o tipo de consumidor (1-Residencial, 2-Comercial, 3-Industrial): ");
        scanf("%d", &tipo);

        switch (tipo) {
            case 1:
                custo = kwh * 0.3;
                total_res += kwh;
                count_res++;
                break;
            case 2:
                custo = kwh * 0.5;
                total_com += kwh;
                count_com++;
                break;
            case 3:
                custo = kwh * 0.7;
                total_ind += kwh;
                break;
            default:
                printf("Tipo de consumidor invalido!\n");
                continue;
        }

        printf("Custo para o consumidor %d: R$ %.2f\n\n", consumidor, custo);
    }

    printf("\nTotal de consumo:\n");
    printf("Residencial: %.2f kWh\n", total_res);
    printf("Comercial: %.2f kWh\n", total_com);
    printf("Industrial: %.2f kWh\n", total_ind);

    if (count_res + count_com > 0) {
        float media = (total_res + total_com) / (count_res + count_com);
        printf("\nMedia de consumo dos tipos 1 e 2: %.2f kWh\n", media);
    }

    return 0;
}