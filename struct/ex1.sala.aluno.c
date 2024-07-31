#include <stdio.h>
#define QUANTIDADE_ALUNOS 5 //Constante 

typedef struct aluno {
    int matricula; 
    int idade;
    char nome[20];
}Aluno; 

int main(void){
    Aluno aluno[QUANTIDADE_ALUNOS];
    int count; 
    
    for(count=0; count < QUANTIDADE_ALUNOS; count++){
    printf("Informe o nome: \t");
    scanf(" %[^\n]", aluno[count].nome);
    printf("Informe a matricula: \t");
    scanf("%d", &aluno[count].matricula);
    printf("Digite a idade: ");
    scanf("%d", &aluno[count].idade);
    }
        
    return 0; 
}