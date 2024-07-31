include <stdio.h>
#include <locale.h>
#include <stdlib.h>

//função que cria vetores do tipo real
float * cria_vetor(int tamanho){
    int * vetor = (float*) malloc (tamanho*sizeof(float)); 
    if (vetor == NULL){
        printf("Sem memória!");
        exit(1);
        }
        else{
        printf ("Vetor alocado.!");
}
return vetor; 
}
    // Função para ler os valores para um vetor do tipo real
void ler_vetor(float * vetor, int tamanho){
    printf("Informe os valores para o vetor: \t");
    for(int index=0; index < tamanho; index++){
    scanf("%f", &vetor[index]);
    }
}
   // função para impprimir os valores
void imprime_vetor(float * vetor, int tamanho){
     for(int index=0; index < tamanho;index++){
    printf("%f\t", vetor[index]);
    }
}
   //função principal
int main(void){

float * vetor = cria_vetor(5);
float * vetor2 = cria_vetor(3);
int tamanho = 5; 

//chamada das funções ler e imprimir
ler_vetor(vetor, tamanho);
imprime_vetor(vetor, tamanho);
//libera vetor da memória 
free(vetor);

return 0;
}