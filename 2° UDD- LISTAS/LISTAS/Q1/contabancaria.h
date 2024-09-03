#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

typedef struct contabancaria ContaBancaria; 

//FUNÇÃO RESPONSÁVEL POR CRIAR UMA CONTA
ContaBancaria * criaConta(char * titular, int numero, double saldo);

//FUNÇÃO RESPONSÁVEL POR REALIZAR O DEPOSITO EM UMA CONTA
void deposita(ContaBancaria * conta, double valor);

//FUNÇÃO RESPONSÁVEL POR SACAR DINHEIRO
int saca(ContaBancaria * conta, double valor);

//FUNÇÃO RESPONSÁVEL POR TRANFERIR O DINHEIRO
int transfere(ContaBancaria * remetente, ContaBancaria * destinatario, double valor);

//FUNÇÃO RESPONSÁVEL POR IMPRIMIR O SALDO 
double saldo(const ContaBancaria * conta);

//FUNÇÃO RESPONSÁVEL POR ECLUIR A CONTA E LIBERAR O ESPAÇO DE MEMÓRIA 
void excluiConta(ContaBancaria * conta);

#endif