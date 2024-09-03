#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disciplina.h"
#include "aluno.h"

Aluno* cria_aluno(const char* nome, int matricula) {
    Aluno* novo_aluno = (Aluno*)malloc(sizeof(Aluno));
    if (novo_aluno == NULL) {
        printf("ERRO: Falha ao alocar memória para aluno.\n");
        exit(1);
    } else {
        strncpy(novo_aluno->nome, nome, sizeof(novo_aluno->nome) - 1);
        novo_aluno->nome[sizeof(novo_aluno->nome) - 1] = '\0'; // Garantir a terminação nula
        novo_aluno->matricula = matricula;
        novo_aluno->num_disciplinas = 0;
        memset(novo_aluno->disciplinas, 0, sizeof(novo_aluno->disciplinas));
    }
    return novo_aluno;
}

void matricula_disciplina(Aluno* aluno, Disciplina* disciplina) {
    if (aluno != NULL && disciplina != NULL && aluno->num_disciplinas < MAX_DISCIPLINAS) {
        for (int i = 0; i < aluno->num_disciplinas; i++) {
            if (aluno->disciplinas[i]->codigo == disciplina->codigo) {
                return; // Disciplina já está matriculada
            }
        }
        aluno->disciplinas[aluno->num_disciplinas++] = disciplina;
    }
}

void exibe_aluno(const Aluno * aluno) {
    if (aluno != NULL) {
        printf("NOME DO ALUNO: %s\n", aluno->nome);
        printf("MATRÍCULA: %d\n", aluno->matricula);
        printf("DISCIPLINAS:\n");
        for (int cont = 0; cont < aluno->num_disciplinas; cont++) {
            printf(" - %s (CÓDIGO: %d)\n", aluno->disciplinas[cont]->nome, aluno->disciplinas[cont]->codigo);
        }
    }
}

void exclui_aluno(Aluno* aluno) {
    if (aluno != NULL) {
        free(aluno);
    }
}