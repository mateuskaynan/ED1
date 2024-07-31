#include <stdio.h>
#include <stdlib.h>

typedef enum meses
{
    JANEIRO = 1,
    FEVEREIRO,
    MARCO,
    ABRIL,
    MAIO,
    JUNHO,
    JULHO,
    AGOSTO,
    SETEMBRO,
    OUTUBRO,
    NOVEMBRO,
    DEZEMBRO
}Meses;

typedef struct data{
    int dia;
    Meses mes;
    int ano;
}Data;

void preenche(Data *p){
    printf("- DIGITE O DIA DE NASCIMENTO: ");
    scanf("%d", &p->dia);
    printf("- DIGITE O MES DE NASCIMENTO: ");
    scanf("%d",(int*) &(p->mes));
    printf("- DIGITE O ANO DE NASCIMENTO: ");
    scanf("%d", &p->ano);
}

void imprime(Data *p){
    printf("\n> %s%d/%s%d/%d", p->dia < 10 ? "0" : "", p->dia, p->mes < 10 ? "0" : "", p->mes, p->ano);
}

int main(void){
    Data data;
    preenche(&data);
    imprime(&data);
    return 0;
}