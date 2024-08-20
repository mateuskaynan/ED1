#include <stdio.h>
#define TAMANHO_MAXIMO 9
#include "numeros_melhor_caso.h"

int main(){
    int dados[TAMANHO_MAXIMO] = {2, 3, 4, 1, 5, 7, 6, 8, 9}; /*VETOR E SEUS NÚMEROS JÁ PRÉ DEFINIDOS*/
    int tamanho = TAMANHO_MAXIMO; /*VARÁVEL RESPONSÁVEL POR ARMAZENAR A QUANTIDADE DE DADOS DENTRO DO VETOR/ARRAY*/  

    /*CHAMADA DA FUNÇÃO PARA EXIBIR OS VETOR E SEUS RESPECTIVOS NÚMEROS ANTES DA ORDENAÇÃO*/
    printf("-------------------- GNOME SORT --------------------");
    printf("\nDADOS DO VETOR ANTES DA ORDENACAO: ");
    mostrarDados(dados, tamanho);
    printf("----------------------------------------------------");
    /*CHAMADA DA FUNÇÃO PARA RELIAZR A ORDENAÇÃO COM O GNOME SORT*/
    ordenacao(dados, tamanho);

    /*CHAMADA DA FUNÇÃO PARA EXIBIR OS DADOS DO VETOR
    DEPOIS DA ORDENAÇÃO*/
    printf("\nDADOS DO VETOR DEPOIS DA ORDENACAO: ");
    mostrarDados(dados, tamanho); 
    printf("----------------------------------------------------");
    return 0; 
}