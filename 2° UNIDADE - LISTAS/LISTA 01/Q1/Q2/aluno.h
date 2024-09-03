#ifndef ALUNO_H
#define ALUNO_H

#include "disciplina.h"

#define MAX_DISCIPLINAS 10

// DEFINIÇÃO DA STRUCT ALUNO
typedef struct {
    char nome[100];
    int matricula;
    Disciplina * disciplinas[MAX_DISCIPLINAS];
    int num_disciplinas;
} Aluno; 

// FUNÇÃO RESPONSÁVEL POR CRIAR UM ALUNO
Aluno* cria_aluno(const char* nome, int matricula);

// FUNÇÃO RESPONSÁVEL POR EXIBIR OS ALUNOS CADASTRADOS E SUAS RESPECTIVAS DISCIPLINAS
void exibe_aluno(const Aluno * aluno); 

// FUNÇÃO RESPONSÁVEL POR MATRICULAR UM ALUNO NUMA DISCIPLINA
void matricula_disciplina(Aluno* aluno, Disciplina* disciplina);

// FUNÇÃO QUE EXCLUI O ALUNO E LIBERA A MEMÓRIA 
void exclui_aluno(Aluno* aluno);

#endif