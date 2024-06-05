#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// exemplo: mudando o tamanho do vetor 
int main(void){
int novo_tamanho; 
int tamanho; 

printf("Digite o tamanho do vetor: ");
scanf("%i". &tamanho);
int * vetor = (int*) calloc(tamanho, sizeof(int)); 

printf("\nDigite um novo tamanho: ");
scanf("%i", &novo_tamanho);
vetor = realloc(vetor, novo_tamanho*sizeof(int));
return 0;

}