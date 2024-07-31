//Considere o trecho de código abaixo:
#include <stdio.h>

int main(){
int x, *p;
x = 100;
p = x;
printf("Valor de p = %p\tValor de *p = %d", p, *p);

/*A mensagem fornecida é de advertência, pois, no na linha 7 não há a presença do & comercinal 
ao lado do x, e é por conta do & que o endereço da variável é acessado*/

int x, *p;
x = 100;
p = &x;
printf("Valor de p = %p\tValor de *p = %d", p, *p);

/*Após a modificação, o programa roda normalmente*/

return 0; 
}