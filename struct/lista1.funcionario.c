#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DEFINIÇÃO DA ESTRTURURA FUNCIONÁRIO
typedef struct {
    char nome[50];
    float salario;
    int identificador;
    char cargo[50];
} Funcionario;

// FUNÇÃO RESPONSÁVEL POR PREENCHER OS DADOS DO FUNCIONÁRIO
void preencherFuncionario(Funcionario *funcionario) {
    printf("- DIGITE NOME DO FUNCIONARIO: ");
    scanf(" %[^\n]s", funcionario->nome);  // Lê uma linha de texto incluindo espaços
    printf("- INFORME O SALARIO DO FUNCIONARIO: ");
    scanf("%f", &funcionario->salario);
    printf("- INFORME IDENTIFICADOR DO FUNCIONARIO: ");
    scanf("%d", &funcionario->identificador);
    printf("- DIGITE CARGO DO FUNCIONARIO : ");
    scanf(" %[^\n]s", funcionario->cargo);  // Lê uma linha de texto incluindo espaços
}

// Função para imprimir os dados de um Funcionário
void imprimirFuncionario(const Funcionario *funcionario) {
    printf("\n> NOME: %s\n", funcionario->nome);
    printf("> SALARIO: %.2f\n", funcionario->salario);
    printf("> IDENTIFICADOR: %d\n", funcionario->identificador);
    printf("> CARGO: %s\n", funcionario->cargo);
}

// Função para alterar o salário de um Funcionário
void alterarSalario(Funcionario *funcionario, float novoSalario) {
    funcionario->salario = novoSalario;
}

// Função para encontrar e imprimir o funcionário com o maior e o menor salário
void imprimirFuncionarioExtremos(Funcionario funcionarios[], int n) {
    if (n <= 0) {
        printf("NUMERO INVALIDO!\n");
        return;
    }

    Funcionario *funcionarioMaiorSalario = &funcionarios[0];
    Funcionario *funcionarioMenorSalario = &funcionarios[0];

    for (int i = 1; i < n; i++) {
        if (funcionarios[i].salario > funcionarioMaiorSalario->salario) {
            funcionarioMaiorSalario = &funcionarios[i];
        }
        if (funcionarios[i].salario < funcionarioMenorSalario->salario) {
            funcionarioMenorSalario = &funcionarios[i];
        }
    }

    printf("\n- MAIOR E MENOR SALARIO -");
    printf("\nMAIOR SALARIO:\n");
    imprimirFuncionario(funcionarioMaiorSalario);
    
    printf("\nMENOR SALARIO:\n");
    imprimirFuncionario(funcionarioMenorSalario);
}

int main() {
    int n;

    // Solicita o número de funcionários
    printf("INFORME O NUMERO DE FUNCIONARIOS: ");
    scanf("%d", &n);

    // Aloca memória para o vetor de funcionários
    Funcionario *funcionarios = (Funcionario *)malloc(n * sizeof(Funcionario));
    if (funcionarios == NULL) {
        printf("ERRO INESPERADO!\n");
        return 1;
    }

    // Preenche os dados dos funcionários
    for (int i = 0; i < n; i++) {
        printf("\n> PREENCHA OS DADOS DO FUNCIONARIO: %d:\n", i + 1);
        preencherFuncionario(&funcionarios[i]);
    }

    // Imprime todos os funcionários
    printf("\n========== FUNCIONÁRIOS ==========\n");
    for (int i = 0; i < n; i++) {
        printf("\nFuncionArio %d:\n", i + 1);
        imprimirFuncionario(&funcionarios[i]);
    }

    // Altera o salário de um funcionário específico
    int index;
    float novoSalario;
    printf("\nDigite o índice do funcionArio para alterar o salário (0 a %d): ", n - 1);
    scanf("%d", &index);
    if (index >= 0 && index < n) {
        printf("Digite o novo salario para o funcionArio %d: ", index);
        scanf("%f", &novoSalario);
        alterarSalario(&funcionarios[index], novoSalario);
        printf("Dados atualizados do funcionário %d:\n", index);
        imprimirFuncionario(&funcionarios[index]);
    } else {
        printf("INDICE INVALIDO.\n");
    }

    // Imprime o funcionário com o maior e menor salário
    imprimirFuncionarioExtremos(funcionarios, n);

    // Libera a memória alocada
    free(funcionarios);

    return 0;
}