#ifndef ALUNO_H
#define ALUNO_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct aluno Aluno;

/*função que aloca memória para struct Aluno */

Aluno *criarAluno(int matricula, char nome[], float media);

void SalvarAlunoEmArquivo(char nome_do_arquivo[], Aluno *aluno);

void exibirAlunos(char *nome_do_arquivo);

#endif //ALUNO_H