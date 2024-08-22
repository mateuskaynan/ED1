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
    { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
      11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
      21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
      31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
      41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
      51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
      61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
      71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
      81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
      91, 92, 93, 94, 95, 96, 97, 98, 99, 100};
    
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