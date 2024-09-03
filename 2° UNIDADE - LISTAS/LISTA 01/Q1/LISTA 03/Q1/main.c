#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"aluno.h"

int main(void){
    Aluno *aluno = criarAluno(123, "Maria", 8.5);
    if (aluno == NULL){
        SalvarAlunoEmArquivo("alunos.txt", aluno);
        exibirAlunos("alunos.txt");
        free(aluno);
    }
    return 0;
}