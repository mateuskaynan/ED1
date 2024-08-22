#include <stdio.h>
#include <stdlib.h>

int main(void){
    int linhas, colunas;
    
    printf("Informe a quantidade de linhas e colunas da matriz: ");
    scanf("%d %d", &linhas, &colunas);
    
    //ALOCAÇÃO DINÂMICA DA MATRIZ
    int ** matriz = (int **) malloc(colunas*sizeof(int*));
    if(matriz == NULL){
        exit(1);
    }
    for (int count = 0; count<linhas;  count++){
    matriz[count] = (int*)malloc(colunas*sizeof(int));
        if(matriz[count] == NULL){
        exit(1); 
       }
    }
    //ELEMENTOS DA MATRIZ 
    printf("Informe os elementos: \n");
    int linha, coluna; 
    for(linha = 0; linha<linhas; linha++){
        for (coluna = 0; coluna<colunas; coluna++){
            scanf("%d", &matriz[linha] [coluna]);
        }
    }
    //IMPRIMIR MATRIZ ORIGINAL
    for(linha = 0; linha<linhas; linha++){
        printf("\n"); 
    } for(coluna = 0; coluna<colunas; coluna++){
        printf("%d\t", matriz[linha][coluna]);
    }
    //MATRIZ TRANSPOSTA
    printf("Matriz Transposta: \n");
    for(linha = 0; linha<linhas; linha++){
        printf("\n");
    } for(coluna = 0; coluna<colunas; coluna++){
        printf("%d\t", matriz[coluna][linha]);
    }
    
    for(linha=0; linha < linhas; linha++){
        free(matriz[linha]);
    }
    return (0);
    }
