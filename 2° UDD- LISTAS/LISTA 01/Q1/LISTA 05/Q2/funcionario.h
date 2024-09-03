#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 //*DEFINIÇÃO DE UM VALOR MÁXIMO PARA O VETOR DE FUNCIONÁRIOS

// DEFINIÇÃO DA STRUCT Funcionário
typedef struct funcionario Funcionario;

// DECLARAÇÃO DAS FUNÇÕES 

//FUNÇÃO RESPONSÁVEL POR ALOCAR O FUNCIONÁRIO
Funcionario **aloca_funcionarios();

//FUNÇÃO RESPONSÁVEL POR ADICIONAR UM NOVO FUNCIONÁRIO 
Funcionario **adiciona_funcionario(Funcionario **funcionarios, char *nome, int id, float salario, int *quantidade);

//FUNÇÃO RESPONSÁVEL POR LISTAR TODOS OS FUNCIONÁRIOS CADASTRADOS
void listar_funcionarios(Funcionario **funcionarios, int quantidade);

//FUNÇÃO RESPONSÁVEL POR BUSCAR UM FUNCIONÁRIO ESPECÍFICO 
Funcionario *busca_funcionario(Funcionario **funcionarios, int id, int quantidade);

//FUNÇÃO RESPONSÁVEL POR REMOVER UM FUNCIONÁRIO CADASTRADO 
Funcionario **remover_funcionario(Funcionario **funcionarios, int id, int *quantidade);

//FUNÇÃO RESPONSÁVEL POR LIBERAR A MEMÓRIA 
void libera_funcionario(Funcionario **funcionarios, int quantidade);

#endif // FUNCIONARIO_H