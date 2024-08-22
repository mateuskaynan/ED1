#include <stdio.h>
#include <stdlib.h>
#define QUANTIDADE_PESSOAS 100 

int main() {
    int n;
    printf("DIGITE O NUMERO DE PESSOAS QUE DESEJA ARMAZENAR: ");
    scanf("%d", &n);

    while (getchar() != '\n');
    char **pessoas = (char **)malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++) {
        pessoas[i] = (char *)malloc(QUANTIDADE_PESSOAS * sizeof(char));
    }

    int *idade = (int *)malloc(n * sizeof(int));

    if (pessoas == NULL || idade == NULL) {
        printf("ERRO INESPERADO!\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        printf("\nNOME COMPLETO: ");
        fgets(pessoas[i], QUANTIDADE_PESSOAS, stdin);
        int j = 0;
        while (pessoas[i][j] != '\0') {
            if (pessoas[i][j] == '\n') {
                pessoas[i][j] = '\0';
                break;
            }
            j++;
        }
        printf("IDADE: ");
        scanf("%d", &idade[i]);
        while (getchar() != '\n');
    }
    printf("\n------------ LISTA DE NOMES ------------\n");
    for (int i = 0; i < n; i++) {
        printf("> %s -  %d ANOS \n", pessoas[i], idade[i]);
    }
    printf("-----------------------------------------");
    for (int i = 0; i < n; i++) {
        free(pessoas[i]);
    }
    free(pessoas);
    free(idade);

    return 0;
}