#include <stdio.h>
#include <locale.h>

typedef enum dias_semana {
    SEGUNDA, 
    TERCA,
    QUARTA,
    QUINTA,
    SEXTA,
    SABADO,
    DOMINGO,
} Semana; 

int main(){
    enum dias_semana dia; 
    dia = SEGUNDA; 
    printf("Dia da semana: %d\n", dia);
    
    
    return 0; 
}