#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum genero{
    MASCULINO = 1, 
    FEMININO,
    NEUTRO
} Genero; 

typedef struct pessoa{
    char nome[20];
    int idade;
    Genero genero; 
} Pessoa;

int main(){
    Pessoa pessoa; 
    char gen[10]; 
    
    printf("DIGITE SEU NOME: ");
    scanf("%s", pessoa.nome);
    
    printf("DIGITE SUA IDADE: ");
    scanf("%d", &pessoa.idade);
    
    printf("DIGITE O SEU GENERO (MASCULINO, FEMININO ou NEUTRO): ");
    scanf("%s ", gen);
    //str
    if (strcmp(gen, "MASCULINO") == 0) {
        pessoa.genero = MASCULINO;
    } else if (strcmp(gen, "FEMININO") == 0) {
        pessoa.genero = FEMININO;
    } else if (strcmp(gen, "NEUTRO") == 0) {
        pessoa.genero = NEUTRO;  
    } else {
        printf("\nATENCÃO: GENERO INVALIDO!\n");
    }

    printf("\n--- DADOS ---");
    printf("\n> NOME: %s", pessoa.nome);
    printf("\n> IDADE: %d", pessoa.idade);
    
    printf("\n> GENERO: ");
    switch (pessoa.genero)
    {
    case MASCULINO:
        printf("MASCULINO");
        break;
    case FEMININO:
        printf("FEMININO");
        break;
    case NEUTRO:
        printf("NEUTRO");
        break;
    default:
        printf("GENERO NAO ENCONTRADO.");
        break;
    }

    return 0;
}