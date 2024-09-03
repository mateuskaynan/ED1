#include <stdio.h>
#include <time.h>
#define TAMANHO_MAXIMO 100

/*FUNÇÃO QUE IRÁ IMPRIMIR OS NÚMEROS ANTES E DEPOIS DA ORDENAÇÃO*/
void mostrarDados(int dados[], int tamanho){
    int i; 
    for(i = 0; i < tamanho; i++){
        printf("%d ", dados[i]);
    }
    printf("\n"); 
}

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

int main(){
    
    clock_t start, end; 
    double time_total;
    start = clock();
    
     /*VETOR E SEUS NÚMEROS JÁ PRÉ DEFINIDOS*/
    int dados[TAMANHO_MAXIMO] = 
    {100, 99, 98, 97, 96, 95, 94, 93, 92, 91,
     90, 89, 88, 87, 86, 85, 84, 83, 82, 81,
     80, 79, 78, 77, 76, 75, 74, 73, 72, 71,
     70, 69, 68, 67, 66, 65, 64, 63, 62, 61,
     60, 59, 58, 57, 56, 55, 54, 53, 52, 51,
     50, 49, 48, 47, 46, 45, 44, 43, 42, 41,
     40, 39, 38, 37, 36, 35, 34, 33, 32, 31,
     30, 29, 28, 27, 26, 25, 24, 23, 22, 21,
     20, 19, 18, 17, 16, 15, 14, 13, 12, 11,
     10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    
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