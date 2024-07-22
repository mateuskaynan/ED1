#include <stdio.h>
#include <stdlib.h>

union tipos {
    int inteiro;
    float real;
    char letra;
};
typedef union tipos Tipos; 

int main(void){
    Tipos variavel;
    
    variavel.inteiro = 2;
    printf("%d, %d, %d", variavel.inteiro);
    
    variavel.real = 2.5;
    printf("%f", variavel.real);
    
    variavel.letra = 's';
    printf ("%d, %f, %c", variavel.inteiro, variavel.real, variavel.letra); 

    return 0;
}