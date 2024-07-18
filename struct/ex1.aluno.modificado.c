// EXERCICIO ALUNO MODIFICADO

#include <stdio.h>
#include <stdlib.h>
#define QUANTIDADE_ALUNOS 1 //Constante 

//ESTRUTURA 
typedef struct aluno {
    int matricula; 
    int idade;
    char nome[20];
}Aluno; 

//CRIAÇÃO DA FUNÇÃO 
void preenche(Aluno * aluno, int tamanho){
    
    int count; 
    for(count=0; count < tamanho; count++){
    printf("------- CADASTRO -------\n");
    printf("NOME: ");
    scanf(" %[^\n]", aluno[count].nome);
    printf("MATRICULA: ");
    scanf("%d", &aluno[count].matricula);
    printf("IDADE: ");
    scanf("%d", &aluno[count].idade);
    printf("------------------------\n");
    }
}

//FUNÇÃO PRINCIPAL
int main(void){
    
    Aluno * aluno = (Aluno*) malloc(QUANTIDADE_ALUNOS*sizeof(Aluno));
    if(aluno==NULL){
        printf("NO memory RAM.");
        exit(1);
    } 
    else {
    }
    
    //CHAMADA DA FUNÇÃO
    preenche(aluno, QUANTIDADE_ALUNOS);
    
    //SOLICITAÇÃO DE NOVO TAMANHO 
    int novo_tamanho;
    printf("\n");
    printf("- INFORME O TAMANHO DO NOVO VETOR: ");
    scanf("%d", &novo_tamanho);
    aluno =(Aluno*) realloc(aluno, novo_tamanho*sizeof(Aluno));
    if(aluno==NULL){
        exit(1);
    } else {
        printf("\n");
        printf("!! Vetor realocado !!\n");
        printf("\n");
    
    }
    preenche(aluno, novo_tamanho);
    return 0; 
}