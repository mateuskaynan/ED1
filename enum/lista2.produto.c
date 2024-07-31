#include <stdio.h>
#include <stdlib.h>

typedef enum produtoo{
    ALIMENTO,
    BEBIDA,
    ELETRONICO
}TipoProduto;

typedef union tipo{
    char alimento[50];
    char bebida[50];
    char eletronico[50];
}Tipo;

typedef struct produto{
    char nome[50];
    float preco;
    Tipo tipo;
    TipoProduto tipoProduto;
}Produto;

void lerProduto(Produto *p){
    printf("PRODUTO: ");
    scanf(" %[^\n]", p->nome);
    printf("PRECO: ");
    scanf("%f", &(p->preco));
    printf("DIGITE: \n1 - ALIMENTO \n2 - BEBIDA \n3 - ELETRONICO \n->\t");
    scanf("%d", (int *)&(p->tipoProduto));
    switch (p->tipoProduto){
    case 1:
        printf("MARCA DO PRODUTO: ");
        scanf(" %[^\n]", p->tipo.alimento);
        break;
    case 2:
        printf("MARCA BEBIDA: ");
        scanf(" %[^\n]", p->tipo.bebida);
        break;
    case 3:
        printf("MARCA DO ITEM: ");
        scanf(" %[^\n]", p->tipo.eletronico);
        break;
    }
}

void imprimirProduto(Produto *p){
    printf("\n------------------------------\n");
    printf("PRODUTO:  %s\n", p->nome);
    printf("PRECO: %.2f\n", p->preco);
    switch (p->tipoProduto)
    {
    case 1:
        printf("MARCA: %s\n", p->tipo.alimento);
        break;
    case 2:
        printf("MARCA BEBIDA: %s\n", p->tipo.bebida);
        break;
    case 3:
        printf("MARCA DO ITEM: %s\n", p->tipo.eletronico);
        break;
    }
    printf("------------------------------\n");
}

int main()
{
    Produto *produto = (Produto *)malloc(sizeof(Produto));
    if(produto == NULL){
        exit(1);
    }
    lerProduto(produto);
    imprimirProduto(produto);
    free(produto);
    return 0;
}