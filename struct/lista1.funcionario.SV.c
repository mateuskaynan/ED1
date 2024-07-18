#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario {
    char nome[20];
    float salario;
    long int identificador; 
    char cargo[20];
} Funcionario;

void preenche(Funcionario * servidor){
    /*FUNÇÃO PARA PREENCHER VARIÁVEL DO TIPO FUNCIONÁRIO*/
    printf("Digite o nome: \t");
    scanf(" %[^\n]", servidor->nome);
    printf("Digite o salário: \t");
    scanf("%f", &servidor->salario);
    printf("Digite o identificador: \t");
    scanf("%d", &servidor->identificador);
    printf("Digite o cargo: ");
    scanf(" %[^\n]", servidor->cargo); 
}

void imprime(Funcionario * servidor){
    /*FUNÇÃO PARA PREENCHER VARIÁVEL DO TIPO FUNCIONÁRIO*/
    
    printf("-- DADOS DO FUNCIONÁRIO --");
    printf("NOME: %s", servidor->nome);
    printf("SALÁRIO: %f", servidor->salario);
    printf("IDENTIFICADOR : %d", servidor->identificador);
    printf("CARGO: %s", servidor->cargo);
    printf("--------------------------"); 
}

int main(void){
    
    return 0;
}