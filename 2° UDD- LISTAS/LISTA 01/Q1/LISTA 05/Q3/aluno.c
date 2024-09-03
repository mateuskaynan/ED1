#include  <stdio.h>
#include <stdlib.h>

typedef struct aluno{
    char nome[50];
    int idade; 
    float nota1;
    float nota2;
    float nota3;
    float media;  
} Aluno; 

Aluno * bubble_sort(Aluno * vet, int tam){
    int i, j; 
    Aluno aux; 
    for (i = 0; i < tam; i++){
        for(j = 0; j < tam - 1; j++){
            if(vet[j].media > vet[j+1].media){
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j + 1] = aux; 
            }

        }

    }
    return vet; 
}

int main(){
    int i = 0; 
    FILE * arquivo = fopen("entrada.txt", "r");
    if(arquivo == NULL){
        printf("ERRO!");
        exit(1); 
    }
    int linhas = 0; 
    char linha[200]; 
    while (fgets(linha, 200, arquivo) != NULL)
    {
        linhas++; 
    }
    printf("%d\n", linhas); 
    Aluno * alunos = (Aluno*)malloc(sizeof(Aluno) * linhas);
    if (alunos == NULL){
        printf("ERRO\n");
        exit(1);    
    }
    rewind(arquivo); 
    while (fscanf(arquivo, "%[^,] %d,%f,%f,%f", alunos[i].nome, &alunos[i].idade, &alunos[i].nota1, &alunos[i].nota2, &alunos[i].nota3) != EOF)
    {
        alunos[i].media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3)/3; 
    }
    
    alunos = bubble_sort(alunos, linhas); 
    for(int contador = 0; contador < linhas; contador++){
        printf("ALUNO %d: %s\nMÉDIA: %.1f\n", contador + 1, alunos[i].nome, alunos[i].media);
    }
    
    for(int contador = 0; contador < linhas; contador++){
        fprintf(arquivo, "NOME: %s\n MEDIA: %.2lf", alunos[i].nome, alunos[i].media);
    }
    fclose(arquivo); 

    arquivo = fopen("resultados.txt", "w");

    for (int contador = 1;contador < linhas;contador++){
        fprintf(arquivo, "ALUNO %d - NOME: %s MEDIA: %.1f\n", contador, alunos[i].nome, alunos[i].media);
    }
    fclose(arquivo); 

    return 0;
}