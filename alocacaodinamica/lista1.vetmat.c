#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetor;
    int tamanho;
    
    printf("DIGITE O TAMANHO DO VETOR: ");
    scanf("%d", &tamanho);

    //ALOCAÇÃO DINÂMICA PARA O VETOR
    vetor = (int *)malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        printf("ERRO!\n");
        return 1;
    }

    //SOLICITAÇÃO DOS ELEMENTOS DO VETOR 
    printf("\nINFORME OS ELEMENTOS DO VETOR\n");
    for (int i = 0; i < tamanho; i++) {
        printf("ELEMENTO %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    //IMPRESSÃO DOS ELEMENTOS NA ORDEM INVERSA
    printf("\n> ELEMENTOS DO VETOR NA ORDEM INVERSA:\n");
    for (int i = tamanho - 1; i >= 0; i--) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);

    return 0;
}