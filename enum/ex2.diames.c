#include <stdio.h>
#include <locale.h>

//ENUM REFERENTE AOS MESES DO ANO
typedef enum mes{
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
}Mes; 

//ENUM REFERENTE AOS DIAS DA SEMANA
typedef enum dias_semana {
    SEGUNDA=2, 
    TERCA,
    QUARTA,
    QUINTA,
    SEXTA,
    SABADO,
    DOMINGO
}DiaSemana; 

int main(){   
    //SOLICITAÇÃO DO MÊS E SWITCH PARA IMPRIMIR
    Mes mes; 
    printf("INFORME O MES: 1 - 12 \n> MES:");
    scanf("%d", &mes);
    switch (mes) {
    case JANEIRO:
        printf("\nMES: JANEIRO");
    break;
    
    case FEVEREIRO:
        printf("\nMES: FEVEREIRO");
    break;
    
    case MARCO:
        printf("\nMES: MARÇO");
    break;
    
    case ABRIL:
        printf("\nMES: ABRIL");
    break;
    
    case MAIO:
        printf("\nMES: MAIO");
    break;
    
    case JUNHO:
        printf("MES: JUNHO");
    break;
    
    case JULHO:
        printf("MES: JULHO");
    break;
    case AGOSTO:
        printf("MES: AGOSTO");
    break;
    case SETEMBRO:
        printf("MES: SETEMBRO");
    break;
    case OUTUBRO:
        printf("MES: OUTUBRO");
    break;
    case NOVEMBRO:
        printf("MES: NOVEMBRO");
    break;
    case DEZEMBRO:
        printf("MES: DEZEMBRO");
    break;
    default:
    printf("MES NÃO CADASTRADO! ");
    break;
    }

    //SOLICITAÇÃO DO DIA DA SEMANA E SWITCH PARA IMPRIMIR
    DiaSemana dia; 
 
    printf("\nINFORME O DIA DA SEMANA: 2 - 8 \n> DIA DA SEMANA: ");
    scanf("%d", &dia);
    
    switch (dia) {
    case SEGUNDA:
        printf("SEGUNDA-FEIRA");
    break;
    
    case TERCA:
        printf("TERCA-FEIRA");
    break;
    
    case QUARTA:
        printf("QUARTA-FEIRA");
    break;
    
    case QUINTA:
        printf("QUINTA-FEIRA");
    break;
    
    case SEXTA:
        printf("SEXTA-FEIRA");
    break;
    
    case SABADO:
        printf("SÁBADO");
    break;
    
    case DOMINGO:
        printf("DOMINGO");
    break;
    default:
    printf("DIA NÃO CADASTRADO! ");
    break;
    }
    
    return 0; 
}