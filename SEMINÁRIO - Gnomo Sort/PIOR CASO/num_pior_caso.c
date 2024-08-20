#include <stdio.h>
#define TAMANHO_MAXIMO 9

/*FUNÇÃO RESPONSÁVEL POR REALIZAR A ORDENAÇÃO DOS DADOS*/
void ordenacao(int dados[], int tamanho){
    int posicao = 0; /*VARIÁVEL RESPONSÁVEL POR MARCAR O PRIMEIRO ÍNDICE*/
    
    while(posicao < tamanho){
    /*if RESPONSÁVEL POR INICIALIZAR E PULAR PARA A POSIÇÃO 1 DO VETOR 
    E ASSIM REALIZAR A COMPARAÇÃO DOS DOIS PRIMEIROS NÚMEROS*/    
        if(posicao == 0){
            posicao++; 
        } 
        /*PARA QUE O VETOR CONTINUE PERCORRENDO, O DADO NA POSIÇÃO 
        ATUAL DEVE SER MAIOR DO QUE O DADO DA POSIÇÃO ANTERIOR*/
        else if (dados[posicao] >= dados[posicao - 1]){
            posicao++; 
        } else {
            /*CASO A CONDIÇÃO ANTERIOR TENHA RETORNADO FALSA, 
            A TROCA DE POSIÇÃO É FEITA*/
            int reserva = dados[posicao];
            dados[posicao] = dados[posicao -1]; 
            dados[posicao - 1] = reserva; 
            posicao--; 
        }
    }

}
/*FUNÇÃO QUE IRÁ IMPRIMIR OS NÚMEROS ANTES E DEPOIS DA ORDENAÇÃO*/
void mostrarDados(int dados[], int tamanho){
    int i; 
    for(i = 0; i < tamanho; i++){
        printf("%d ", dados[i]);
    }
    printf("\n"); 
}