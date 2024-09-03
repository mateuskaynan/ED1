#include "funcionario.h"

int main(){
    Funcionario **funcionarios = aloca_funcionarios();
    int quantidade = 0;
    int opcao;
    char nome[50];
    int id;
    float salario;
    Funcionario *f;

    do{
        printf("\n----- MENU DE OPCOES -----\n");
        printf("1 - ADICIONAR FUNCIONARIO\n");
        printf("2 - REMOVER FUNCIONARIO \n");
        printf("3 - PROCURAR FUNCIONARIO\n");
        printf("4 - MOSTRAR FUNCIONARIOS CADASTRADOS\n");
        printf("5 - SAIR\n");
        printf("\n------------------------------");
        printf("\n> DIGITE A OPCAO QUE DESEJA: ");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            printf("\n----- PREENCHA OS CAMPOS CORRESPONDENTES -----");
            printf("INFORME O NOME DO FUNCIONARIO:: ");
            scanf(" %[^\n]", nome);
            printf("Digite o ID do funcionario: ");
            scanf("%d", &id);
            printf("Digite o salario do funcionario: ");
            scanf("%f", &salario);
            funcionarios = adiciona_funcionario(funcionarios, nome, id, salario, &quantidade);
            printf("\n-----------------------------------------------");
            break;
        case 2:
            printf("\n> DIGITE O ID DO FUNCIONARIO QUE DESEJA REMOVER: ");
            scanf("%d", &id);
            funcionarios = remover_funcionario(funcionarios, id, &quantidade);
            break;
        case 3:
            printf("\n> DIGITE O ID SO FUNCIONARIO QUE DESJEA BUSCAR: ");
            scanf("%d", &id);
            f = busca_funcionario(funcionarios, id, quantidade);
            if (f != NULL){
                printf("\n- FUNCIONARIO ENCONTRADO.");
            }
            else{
                printf("\n- FUNCIONARIO NÃO ENCONTRADO!\n");
            }
            break;
        case 4:
            printf("\n> FUNCIONÁRIOS CADASTRADOS: ");
            listar_funcionarios(funcionarios, quantidade);
            break;
        case 5:
            printf("SAINDO\n");
            break;
        default:
            printf("\nOPCAO NÃO CORRESPONDENTE!\n");
        }

    } while (opcao != 5);

    libera_funcionario(funcionarios, quantidade);
    return 0;
}