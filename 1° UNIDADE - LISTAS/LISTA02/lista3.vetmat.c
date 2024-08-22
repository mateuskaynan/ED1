#include <stdio.h>
#include <stdlib.h>

// FUNÇÃO RESPONSÁVEL POR PREENCHER A MATRIZ
void preenche(int **matriz, int n){
    int i, j; 
    for (i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            matriz[i][j] = rand() % 100 + 1;/*A MATRIZ ESTÁ RECEBENDO A FUNÇÃO rand() 
                                            RESPONSÁVEL POR PREENCHER COM NÚMEROS ALETÓRIOS*/ 
        } 
    }
}

//FUNÇÃO RESPONSÁVEL POR IMPRIMIR OS VALORES DA MATRIZ 
void imprime (int **matriz, int n){
    int i, j; 
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("%3d ", matriz[i][j]);
        }
        printf("\n"); 
    }
}

int main(){
    int n, i; 
    //SOLICITAÇÃO DO NÚMERO PARA O USUÁRIO
    printf("DIGITE UM NUMERO: ");
    scanf("%d", &n); 

    //ALOCAÇÃO DINAMICA DO NÚMERO FORNECIDO  
    int **matriz = (int **)malloc(n * sizeof(int *));
    for(i = 0; i < n; i++){
        matriz[i] = (int *)malloc(n * sizeof(int));
    }

    //CHAMADA DA FUNÇÃO PREENCHE, RESPONSÁVEL POR PREENCHER A MATRIZ 
    preenche(matriz, n);
    //CHAMADA DA FUNÇÃO IMPRIME PARA IMPRIMIR OS NÚMEROS PREENCHIDOS NA FUNÇÃO ANTERIOR 
    imprime(matriz, n);

    //LIBERAÇÃO DE MEMÓRIA 
    for(int i = 0; i < n; i++){
        free(matriz[i]); 
    }
    free(matriz);
    
    return 0; 
}