#include <stdio.h>
/*
UNION: 
- USADOS QUANDO QUEREMOS ARMAZENAR VALORES HETEROGENEOS EM UM MESMO ESPAÇO DE MEMÓRIA;
- OS PARÂMETROS COMPARTILHAM O MESMO ESPAÇO DE MRMÓRIA;
- SÓ PODEMOS ARMAZENAR UM PARÂMETRO POR VEZ;
*/

/*EXEMPLO: COMO USAR UNION E STRUCTS*/

typedef union documentos{
    char cpf[11]; //Formato 00.000.000-00
    char RG[9]; //APENAS NÚMEROS INTEIROS 00111000111

} Documentos;

typedef struct pessoa{
    char nome[20]; //PARA GUARDAR O NOME COMPLETO DA PESSOA
    Documentos documento; // PARA GUARDAR CPF OU RG

} Pessoa;

/*FUNÇÃO PARA PREENCHER STRUCT PESSOA*/
void preenche_pessoa(Pessoa * pessoa){
    int opcao_documento; 
    printf("DIGITE SEU NOME: ");
    scanf(" %[^\n]", pessoa->nome); 
    printf("DIGITE: '1' CPF - '2' RG \n>  ");
    scanf("%d", &opcao_documento);
    
    switch(opcao_documento){
        case 1: 
              printf("\nINFORME SEU CPF: ");
              scanf(" %[^\n]", pessoa->documento.cpf);
              break;
        case 2: 
              printf("\nINFORME SEU RG: ");
              scanf (" %[^\n]", pessoa->documento.RG); 
              break; 
        default:
              printf("!VALOR INVÁLIDO!");
        break;
    }
}

/*FUNÇÃO PARA IMPRIMIR PESSOA*/
void imprime_pessoa(Pessoa * pessoa){
    printf("\n> NOME: %s", pessoa->nome); 
    printf("\n> DOCUMENTO: %s", pessoa->documento.cpf);
}

int main(void){
    Pessoa pessoa; 
    preenche_pessoa(&pessoa);
    imprime_pessoa(&pessoa); 

    return 0; 
}