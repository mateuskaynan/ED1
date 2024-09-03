#include <stdio.h>
#include <time.h>
# define TAMANHO 200000 

int compare(const void *a, const void *b){
    return (*(int *)a - *(int *)b); 
}

//FUNÇÃO QUE BUSCA MAIOR ELEMENTO DENTRO DE UM VETOR 
int busca_sequencial(int * entrada, int tamanho){
    int maior = entrada[0]; 
    //BUSCA LINEAR/SEQUENCIAL 
    for (int contador = 0; contador < tamanho; contador++){
        if (maior < entrada[contador]){
            maior=entrada[contador]; 
        }
    }
    return maior; 
}

int busca_binaria(int vet[], int maior, int tamanho){
    int inicio = 0;
    int final = tamanho-1; 
    while (inicio <= final)
    {
        int meio = inicio + (final - inicio)/2; 
        if (vet[meio] == maior){
            return vet[meio];
        }
        else if(vet[meio] < maior){
            inicio = meio + 1; 
        }
        else {
            final = meio - 1;
        }
    }
    return - 1; 
}

int main(){
    int entrada[TAMANHO]; 
    
    for (int contador = 0; contador <= TAMANHO; contador++){
        entrada[contador] = rand();
    }
    clock_t tempo_inicial = clock(); 
    //FUNÇÃO DE BUSCA O(n)
    int maior = busca_sequencial(entrada, TAMANHO); 
    double tempo_final = (double)(clock() - tempo_inicial)/CLOCKS_PER_SEC;
    tempo_final = tempo_final * 1000;
    printf("MAIOR ELEMENTO: %d\n", maior);
    printf("TEMPO DE EXECUÇÃO: %.4f", tempo_final); 
    
    qsort(entrada, TAMANHO, sizeof(int), compare);
    //FUNÇÃO DE BUSCA O(n log n)
    tempo_inicial = clock(); 

    int maior2 = busca_binaria(entrada, maior, TAMANHO); //COMPLEXIDADE
    
    tempo_final = (double)(clock() - tempo_inicial)/CLOCKS_PER_SEC; //COMPLEXIDADE O(log(n))
    tempo_final = tempo_final * 1000; //MILISEGUNDOS
    printf("\nMAIOR ELEMENTO: %d\n", maior2);
    printf("TEMPO DE EXECUÇÃO: %.4f", tempo_inicial);  

    return 0; 
}