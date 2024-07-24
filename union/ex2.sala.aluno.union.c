#include <stdio.h>
#include <stdlib.h>

typedef union documentos{
    long int cpf; 
    long int rg; 
    long int sus;
    long int titulo;
    long int passaporte;
} Documentos; 

typedef struct aluno {
    char nome[20];
    char matricula[11];
    int opcao_doc;
    Documentos documento;  
} Aluno;   

//FUNÇÃO CORRESPONDENTE AO PREENCHIMENTO DOS DADOS DO ALUNO 
void preenche_aluno(Aluno *aluno){
    printf("\nDIGITE SEU NOME: ");
    scanf(" %[^\n]", aluno->nome);
    printf("DIGITE A SUA MATRICULA: ");
    scanf (" %[^^=\n]", aluno->matricula);
    printf("\nDIGITE A OPCAO QUE DESEJA: \n1 - CPF \n2 - RG \n3 - SUS \n4 - TITULO DE ELEITOR \n5 - PASSAPORTE");
    printf("\nOPCAO > ");
    scanf("%d", &aluno->opcao_doc);
    printf("\n- PREENCHA O CAMPO CORRESPONDENTE: ");  
    
    switch (aluno->opcao_doc) {
    case 1:
          printf("\nDIGITE SEU CPF:");
          scanf("%ld", &aluno->documento.cpf);
          printf("=================================");
          break;
    case 2:
          printf("\nDIGITE SEU RG:");
          scanf("%ld", &aluno->documento.rg);
          printf("=================================");
          break;
    case 3:
          printf("\nDIGITE SEU NÚMERO DO SUS:");
          scanf("%ld", &aluno->documento.sus);
          printf("=================================");
          break;
    case 4:
          printf("\nDIGITE SEU TITULO DE ELEITOR:");
          scanf("%ld", &aluno->documento.titulo);
          printf("=================================");
          break;
    case 5:
          printf("\nDIGITE SEU PASSAPORTE:");
          scanf("%ld", &aluno->documento.passaporte);
          printf("=================================");
          break;
    default:
          printf("\n!OPÇÃO INVÁLIDA!");
          printf("=================================");
        break;
    }

}

//FUNÇÃO CORRESPONDENTE A IMPRESSÃO DOS DADOS DO ALUNO
void imprime(Aluno * aluno){
    switch (aluno->opcao_doc)
    {
    case 1:
        printf("\nNOME: %s \nMATRICULA: %s \nCPF: %ld", aluno->nome, aluno->matricula, aluno->documento.cpf);
        break;
        getchar();
    case 2: 
        printf("\nNOME: %s \nMATRICULA: %s \nRG: %ld", aluno->nome, aluno->matricula, aluno->documento.rg);
        break;
        getchar();
    case 3: 
        printf("\nNOME: %s \nMATRICULA: %s \nSUS: \t%ld", aluno->nome, aluno->matricula, aluno->documento.sus);
        break;
        getchar();
    case 4: 
        printf("\nNOME: %s \nMATRICULA: %s \nTITULO: %ld", aluno->nome, aluno->matricula, aluno->documento.titulo);
        break;
        getchar();
    case 5: 
        printf("\nNOME: %s \nMATRICULA: %s \nPASSAPORTE: %ld", aluno->nome, aluno->matricula, aluno->documento.passaporte);
        break;
        getchar();
    default:
        break;
    }
}

int main(){
    Aluno * aluno = (Aluno *)malloc(sizeof(Aluno));
    int quantidade;
    printf("DIGITE O NUMERO DE ALUNOS: ");
    scanf("%d", &quantidade);
    //FOR QUE PERMITE PREENCHER A QUANTIDADE DE ALUNO DESEJADO
    for(int cont = 0; cont < quantidade; cont++){
        printf("\nALUNO - %d", cont+1);
        preenche_aluno(aluno); 
    }
    //FOR QUE PERMITE IMPRIMIR TODOS OS ALUNOS CADASTRADOS
    for(int cont = 0; cont < quantidade; cont++){
     printf("\nALUNO - %d", cont+1);   
    imprime(aluno);
    }
    return 0; 
}