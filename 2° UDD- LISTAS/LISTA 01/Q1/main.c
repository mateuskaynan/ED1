#include <stdio.h>
#include "contabancaria.h"

int main(){

ContaBancaria * conta1 = criaConta("Mateus", 12345, 2000.0);
ContaBancaria * conta2 = criaConta("Kainan", 678910, 2000.0); 

printf("> SALDO CONTA 1: %2.f", saldo(conta1));
printf("> SALDO CONTA 2: %2.f", saldo(conta2));

deposita(conta1, 300.0);
printf("\n----------------------------------------------------------------");
printf("\n> SALDO DA CONTA '1' DEPOIS DO DEPOSITO: %2.f", saldo(conta1));
printf("\n----------------------------------------------------------------");
deposita(conta2, 300.0);
printf("\n----------------------------------------------------------------");
printf("\n> SALDO DA CONTA '2' DEPOIS DO DEPOSITO: %f", saldo(conta2));
printf("\n----------------------------------------------------------------");

saca(conta1, 100.0);
printf("\n----------------------------------------------------------------");
printf("\n> SALDO DA CONTA '1' DEPOIS DO SAQUE: %2.f", saldo(conta1));
printf("\n----------------------------------------------------------------");
saca(conta2, 100.0);
printf("\n----------------------------------------------------------------");
printf("> SALDO DA CONTA '2' DEPOIS DO SAQUE: %2.f", saldo(conta2));
printf("\n----------------------------------------------------------------");

transfere(conta1, conta2, 100.0);
printf("\n----------------------------------------------------------------");
printf("\n> SALDO DA CONTA '1' APOS A TRANSFERENCIA: %2.f", saldo(conta1));
printf("> SALDO DA CONTA '2' APOS A TRANSFERENCIA: %f.2", saldo(conta2));
printf("\n----------------------------------------------------------------");

excluiConta(conta1);
excluiConta(conta2); 

return 0; 
}