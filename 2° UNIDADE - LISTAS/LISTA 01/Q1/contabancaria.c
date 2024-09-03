#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contabancaria.h"

struct contabancaria {
    char titular[50];
    int numero;
    double saldo; 
};

ContaBancaria * criaConta(char * titular, int numero, double saldo){
    ContaBancaria * conta_nova = (ContaBancaria*)malloc(sizeof(ContaBancaria));
    if (conta_nova = NULL){
        printf("ERRO!");
    } else {
        strncpy(conta_nova->titular, titular, sizeof(conta_nova->titular) - 1);
        conta_nova->titular[sizeof(conta_nova) - 1] = '\0';
        conta_nova->numero = numero;
        conta_nova->saldo = saldo;  
    }
    return conta_nova; 
}

void deposita(ContaBancaria * conta, double valor){
    if(conta != NULL && valor > 0){
        conta->saldo = conta->saldo + valor;
        printf("DEPOSITO REALIZADO COM SUCESSO!"); 
    }
}

int saca(ContaBancaria * conta, double valor){
    if (conta != NULL && valor > 0 && valor <= conta->saldo){
        conta->saldo = conta->saldo - valor; 
        printf("SAQUE REALIZADO COM SUCESSO!"); 
    } else {
        printf("SALDO INSUFIIENTE!");
    }
}

int transfere(ContaBancaria * remetente, ContaBancaria * destinatario, double valor){
    if(remetente != NULL && destinatario != NULL && valor <= remetente->saldo){
        remetente->saldo = remetente->saldo - valor; 
        destinatario->saldo = destinatario->saldo + valor; 
        printf("TRANSFERECIA REALIZADA COM SUCESSO!");
    } else {
        printf("FALHA NA TRANSFERENCIA!");
    }
}

double saldo(const ContaBancaria * conta){
    if(conta != NULL){
        printf("SALDO: %2.lf", conta->saldo);
    } else {
        printf("CONTA INVÁLIDA OU SALDO NEGATIVO!"); 
    }
}

void excluiConta(ContaBancaria * conta){
    if (conta != NULL){
        free(conta); 
    }
}