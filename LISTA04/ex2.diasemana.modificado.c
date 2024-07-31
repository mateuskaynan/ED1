#include <stdio.h>
#include <locale.h>

typedef enum dias_semana {
    SEGUNDA=2, 
    TERCA,
    QUARTA,
    QUINTA,
    SEXTA,
    SABADO,
    DOMINGO,
}DiaSemana; 

int main(){
    DiaSemana dia;  
    printf("INFORME O DIA DA SEMANA: 2 - 8 \t");
    scanf("%d", &dia);
    
    switch (dia) {
    case SEGUNDA:
        printf("SEGUNDA-FEIRA");
    break;
    
    case TERCA:
        printf("TERÇA-FEIRA");
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