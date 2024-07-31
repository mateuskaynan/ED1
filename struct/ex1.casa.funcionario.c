#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario {
    char nome[20];
    float salario;
    long int identificador; 
    char cargo[20];
} Funcionario;

//FUNÇÃO PARA PREENCHER VARIÁVEL DO TIPO FUNCIONÁRIO
void preenche(Funcionario * funcionario){
    printf("DIGITE O NOME: \t");
    scanf(" %[^\n]", funcionario->nome);
    printf("DIGITE O SALARIO: \t");
    scanf("%f", &funcionario->salario);
    printf("DIGITE O IDENTIFICADOR: \t");
    scanf("%d", &funcionario->identificador);
    printf("DIGITE O CARGO: ");
    scanf(" %[^\n]", funcionario->cargo); 
}

void imprime(Funcionario * funcionario){
    //FUNÇÃO PARA IMPRIMIR OS DADOS
    printf("-- DADOS DO FUNCIONÁRIO --");
    printf("NOME: %s", &funcionario->nome);
    printf("SALÁRIO: %f", &funcionario->salario);
    printf("IDENTIFICADOR : %d", funcionario->identificador);
    printf("CARGO: %s", funcionario->cargo);
    printf("--------------------------"); 
}

//FUNÇÃO QUE POSSIBILITA A ALTERAÇÃO DO SALÁRIO 
void alterarSalario(Funcionario *funcionario, float novoSalario) {
    funcionario->salario = novoSalario;
}

//FUNÇÃO PARA IMPRIMIR O FUNCIONÁRIO DE MELHOR E PIOR SALÁRIO
void melhorSalario(Funcionario funcionarios[], int n) {
    if (n <= 0) {
        printf("!! FUNCIONÁRIO NÃO ENCONGTRADO !!\n");
        return;
    }
}

int main(void){
    int numFuncionario; 
    
    printf("INFORME O NÚMERO DE FUNCIONÁRIOS: ");
    scanf("%d", &numFuncionario);

    //ALOCAÇÃO RESPONSÁVEL PELA QUANTIDADE DE FUNCIONÁRIOS 
    Funcionario *funcionarios = (Funcionario *)malloc(numFuncionario * sizeof(Funcionario));
    if (funcionarios == NULL) {
        printf("NÚMERO INVÁLIDO\n");
        return 1;
    }

    // Preenche os dados dos funcionários
    for (int i = 0; i < numFuncionario; i++) {
        printf("Preenchendo dados do funcionário %d:\n", i + 1);
        preencherFuncionario(&funcionarios[i]);
    }

    return 0;
}