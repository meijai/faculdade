//Alunos Bruno Furlan e Lucas Piva Bellaver.
#include <stdio.h>

int verificacao(int *vetor, int t1, int e) {
    for (int i = 0; i < t1; i++) {
        if (vetor[i] == e) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int t2, i, ret;

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &t2);
    
    int vetor[t2];

    for (i = 0; i < t2; i++) {
        printf("Elemento vetor %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    int e2;
    printf("Informe um elemento para buscar no vetor: ");
    scanf("%d", &e2);

    ret = verificacao(vetor, t2, e2);
    
    if (ret) {
        printf("O numero esta no vetor.\n");
    } else {
        printf("O numero nao esta no vetor.\n");
    }

    return 0;
}
