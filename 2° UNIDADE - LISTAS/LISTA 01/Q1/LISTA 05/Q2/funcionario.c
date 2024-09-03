#include "funcionario.h"

struct funcionario {
    char nome[50];
    int id;
    float salario;
};

Funcionario **aloca_funcionarios(){
    Funcionario **new = (Funcionario**) malloc (sizeof(Funcionario *) *MAX); 
    if(new == NULL){
        printf("ERRO!\n");
        exit(1); 
    }
    return new; 
}
Funcionario **adiciona_funcionario(Funcionario **funcionarios, char *nome, int id, float salario, int *quantidade){
        funcionarios[(*quantidade)] = (Funcionario *)malloc(sizeof(Funcionario)); 
        if (funcionarios[(*quantidade)] == NULL){
            printf("ERRO!");
            exit(1);
        } 
        funcionarios[(*quantidade)]->id = id; 
        funcionarios[(*quantidade)]->salario = salario; 
        strcpy(funcionarios[(*quantidade)]->nome, nome); 
        (*quantidade)++; 
        return funcionarios; 
}

void listar_funcionarios(Funcionario **funcionarios, int quantidade){
    for (int contador = 0; contador < quantidade; contador++){
        printf("- NOME: %s\n- ID: %d\n- SALARIO: %.2f", funcionarios[contador]->nome, funcionarios[contador]->id, funcionarios[contador]->salario);
    }
}

Funcionario *busca_funcionario(Funcionario **funcionarios, int id, int quantidade){
    for (int contador = 0; contador < quantidade; contador++){
        if (funcionarios[contador]->id == id){
            return funcionarios[contador]; 
        }
    }
    return NULL;
}

Funcionario **remove_funcionario(Funcionario **funcionario, int id, int *quantidade){
    int i; 
    for (int contador = 0; contador < (* quantidade); contador++){
        if(funcionario[contador]->id == id){
            break; 
        }
    }
    free(funcionario[i]);
    for (int j = i; j < (*quantidade); j++){
        funcionario[j] = funcionario[j+1];
    }

    funcionario[(*quantidade)] == NULL;
    (*quantidade)--; 
    return funcionario; 
}

void libera_funcionario(Funcionario **funcionarios, int quantidade){
    for (int contador = 0; contador < quantidade; contador++){
        free(funcionarios[contador]);
    }
    free(funcionarios); 
}