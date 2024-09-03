#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"aluno.h"


struct aluno{
    int matricula;
    char nome[50];
    float media;
};

Aluno *criarAluno(int matricula, char nome[], float media){
    Aluno aluno =(Aluno) malloc(sizeof(Aluno));
    if(aluno == NULL){
        printf("erro ao alocar!");
        return NULL;
    }
    aluno->matricula=matricula;
    strcpy(aluno->nome,nome);
    aluno->media=media;
    return aluno;
}

void SalvarAlunoEmArquivo(char nome_do_arquivo[], Aluno *aluno){
    FILE *arq = fopen(nome_do_arquivo, "a");
    if(arq == NULL){
        printf("erro ao abrir o arquivo!\n");
        return;
    }
    fprintf(arq, "%d\t%s\t%.2f\n", aluno->matricula, aluno->nome, aluno->media);
    fclose(arq);
}
void exibirAlunos(char *nome_do_arquivo){
    Aluno aluno;
    int cont = 1;
    FILE *arq = fopen(nome_do_arquivo, "r");
    if(arq == NULL){
        printf("erro ao abrir o arquivo!\n");
        return;
    }
    while(fscanf(arq, "%d\t%s\t%f\n", &aluno.matricula, aluno.nome, &aluno.media) != EOF){
        printf("Aluno %d: %d\t%s\t%.2f\n", cont, aluno.matricula, aluno.nome, aluno.media);
        cont++;
    }
    fclose(arq);
}