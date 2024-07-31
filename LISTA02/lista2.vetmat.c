#include <stdio.h>
#include <stdlib.h>

int main() {
    int **matriz;
    int **matransposta; 
    int linhas, colunas;

    //SOLICITAÇÃO DA QUANTIDADE DE LINHAS E COLUNAS 
    printf("- NUMERO DE LINHAS: ");
    scanf("%d", &linhas);
    printf("- NUMERO DE COLUNAS: ");
    scanf("%d", &colunas);

    //ALOCAÇÃO DA MEMÓRIA PARA MATRIZ
    matriz = (int **)malloc(linhas * sizeof(int *));
    if (matriz == NULL) {
        printf("ERRO!\n");
        return 1;
    }

    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
        if (matriz[i] == NULL) {
            printf("ERRO!\n");
            return 1;
        }
    }

    //ALOCAÇÃO DA MEMÓRIA DA MATRIZ TRANSPOSTA
    matransposta = (int **)malloc(colunas * sizeof(int *));
    if (matransposta == NULL) {
        printf("ERRO!\n");
        return 1;
    }

    for (int i = 0; i < colunas; i++) {
        matransposta[i] = (int *)malloc(linhas * sizeof(int));
        if (matransposta[i] == NULL) {
            printf("ERRO\n");
            return 1;
        }
    }

    //SOLICITAÇÃO E ARMAZENAMENTO DOS ELEMENTOS
    printf("DIGITE OS ELEMENTOS DA MATRIZ:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("> ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matransposta[j][i] = matriz[i][j];
        }
    }

    //IMPRESSÃO DA MATRIZ ORIGINAL 
    printf("\nORIGINAL: \n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    //IMPRESSÃO DA MATRIZ TRANSPOSTA 
    printf("TRANSPOSTA: \n");
    for (int i = 0; i < colunas; i++) {
        for (int j = 0; j < linhas; j++) {
            printf("%d ", matransposta[i][j]);
        }
        printf("\n");
    }

    return 0;
}