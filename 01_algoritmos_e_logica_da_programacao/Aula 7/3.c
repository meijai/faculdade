#include <stdio.h>

int main() {
    int num = 1;
    int limite = 1000000;
    while (num <= limite) {
        if (num % 11 == 0 && num % 13 == 0 && num % 17 == 0) {
            printf("O primeiro numero entre 1 e 1 milhão que e divisivel por 11, 13 e 17 e: %d\n", num);
            break;
        }
        num++;
    }
    return 0;
}