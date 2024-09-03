#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disciplina.h"

struct disciplina {
    char nome[20];
    int codigo;
}; 

Disciplina * cria_disciplina(const char * nome_disciplina, int codigo) {
    Disciplina * nova_disciplina = (Disciplina*)malloc(sizeof(Disciplina));
    if (nova_disciplina == NULL) {
        printf("ERRO: Falha ao alocar memória para disciplina.\n");
        exit(1); 
    } else {
        strncpy(nova_disciplina->nome, nome_disciplina, sizeof(nova_disciplina->nome) - 1);
        nova_disciplina->nome[sizeof(nova_disciplina->nome) - 1] = '\0';
        nova_disciplina->codigo = codigo; 
    }
    return nova_disciplina; 
}

void exclui_disciplina(Disciplina * disciplina) {
    if (disciplina != NULL) {
        free(disciplina);
    }
}