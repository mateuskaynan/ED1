//Quais serão os valores de x, y e p ao final do trecho de código abaixo:

#include <stdio.h>

int main(){
    
    int x, y, *p; /*Criação das vvariáveis x, y e do ponteiro p*/
    
    y = 0; /*A variável y é inicializada com 0, ou seja, y passa a ser 0*/
    
    p = &y; /*p recebe o endereço de y*/
    
    x = *p; /*x recebe o ponteiro p que aponta para a variável y. Com isso, x passa a ser 0*/
    
    x = 4; /*O valor de x é alterado para 4*/
    
    (*p)++; /*p que aponta para y que é 0, passa a ser 1 por conta da incrementação*/
    
    --x; /*x que era 4, passa a ser 3 por conta da decrementação*/
    
    (*p) += x; /*p que é y(1) é somado com x(3) e após ser realizada a soma, o resultado 
             é atribuido a p(y), assim, passando a ser 4 ---> y(4) = y(1) + x(3))*/

             /*Com isso x = 3, y = 4, p = (endereço de y)*/    

return 0;
}