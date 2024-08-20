#include <stdio.h>
#include <time.h>
#define TAMANHO_MAXIMO 9
#include "numeros_melhor_caso.h"

int main(){
    
    clock_t start, end; 
    double time_total;
    start = clock();
    
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
    
    end = clock();
    time_total = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTEMPO DE EXECUCAO: %f segundos\n", time_total);
    
    return 0; 
}