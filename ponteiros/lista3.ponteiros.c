//Qual será a saída exibida pelo programa a seguir:

#include <stdio.h>

int main(void) {

 int a, b, c, d; /*Declaração de 4 variáveis do tipo inteiro*/  

 int *p1; /*Criação de um ponteiro do tipo inteiro*/

 int *p2 = &a; /*Criação de um ponteiro (p2) do tipo inteiro 
               inicializado apontando para o endereço da variável 'a'*/ 

 int *p3 = &c; /*Criação de mais um ponteiro (p3) do tipo inteiro
               que também se inicializa armazenando o endereço da variável c*/

 p1 = p2; /*nesse momento o ponteiro p1 passa a apontar também 
          para o edereço da variável 'a', assim como o p2*/

 *p2 = 10; /*O ponteiro p2 está apontando para a variável 'a' e por conta disso a 
        variável 'a' passa a armazenar o valor 10, como mostra a atribuição fieta no código*/

 b = 20; /*Nessa linha acontece uma atribuição de valor para a variável 'b' 
         com isso, 'b' passa a armazenar 20*/

 int **pp; /*Criação de um ponteiro que aponta para um outro ponteiro,
           também chamado de ponteiro para ponteiro*/

 pp = &p1; /*Tendo em vista que pp é um ponteiro que aponta para um outro ponteiro, 
           nessa linha de código, o 'pp' é inicializado com o endereço do ponteiro p1(10)*/

 *p3 = **pp; /*p3 aponta para c, e pp aponta para p1 que aponta para a(10), 
             com isso, p3 (que aponta para c) passa a ser também 10*/

 int *p4 = &d; /*ponteiro p4 criado e já inicializado apontando para d, 
               que receberá 'b + (*p1)++'*/

 *p4 = b + (*p1)++; /*p4(d) recebrá 30, pois, é realizada a soma de b(10) + p1(a = 10), 
                    e  logo após é realizada a incrementação de p1(a = 10) + 1*/

 printf("%d\t%d\t%d\t%d\n", a, b, c, d);/*com isso: 
                                          a = 11 (por conta do incremento)
                                          b = 20
                                          c = 10 
                                          d = 30*/

}