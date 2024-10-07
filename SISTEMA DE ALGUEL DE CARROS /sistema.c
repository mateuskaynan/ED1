#include "sistema.h"

#define MAX_NOME 51
#define MAX_DOCUMENTO 12
#define MAX_TELEFONE 10 
#define MAX_MODELO 16

typedef struct cliente{
    //ARRAY QUE ARMAZENA O NOME DO CLIENTE
    char nome[MAX_NOME];
    //ARRAY QUE ARMAZENA O DOCUMENTO QUE IDENTIFICA O CLIENTE
    char documento_cliente[MAX_DOCUMENTO];
    //ARRAY QUE ARMAZENA O TELEFONE DO CLIENTE 
    char telefone_cliente[MAX_TELEFONE];
    //PONTEIRO PARA O PROXIMO CLIENTE DA LISTA
    struct Cliente * prox_cliente; 
    //PONTEIRO PARA O CLIENTE ANTERIOR DA LISTA
    struct Cliente * cliente_ant;
    //PONTEIRO PARA OBJETO DO TIPO Carro (CARRO ALUGADO)
    Carro * carro; 
    //ARRAY QUE ARMAZENA A DATA DO ALUGUEL
    char data_aluguel[11]; 
    //VARIÁVEL QUE REPRESENTA A DURAÇÃO DO ALUGUEL EM DIAS 
    int duracao_aluguel;
}Cliente;

struct carro{
    //CÓDIGO IDENTIFICADOR DO CARRO 
    int codigo_carro; 
    //ARMAZENA O MODELO DO CARRO  
    char modelo[MAX_MODELO];
    //ARMAZENA O PREÇO DO CARRO
    float preco_carro; 
    //1: DISPONÍVEL 0: INDISPONÍVEL 
    int disponibilidade;
    //PONTEIRO QUE APONTA PARA O CARRO ANTERIOR DA LISTA
    struct Carro * carro_ant; 
    //PONTEIRO QUE APONTA PARA PRÓXIMO CARRO DA LISTA
    struct Carro * prox_carro; 
};

struct sistema{
    Carro * carro; 
    Cliente * cliente; 
};

Carro * criar_carro(int codigo, const char * modelo, float preco){
    //ALOCA novo_carro NA MEMÓRIA 
    Carro * novo_carro = (Carro*)malloc(sizeof(Carro));
    if(novo_carro == NULL){
        printf("ERRO NA ALOCACAO!");
        exit(1); 
    }
    
    //ATRIBUI O CÓDIGO PASSADO COMO ARGUMENTO 
    novo_carro->codigo_carro = codigo;
    //COPIA O MODELO PASSADO PARA O CAMPO MODELO  
    strcpy(novo_carro->modelo, modelo);
    //ATRIBUI O PRECO PASSADO COMO ARGUMENTO
    novo_carro->preco_carro = preco; 
    //DEFINE O CARRO x COMO DISPONÍVEL(1)
    novo_carro->disponibilidade = 1;
    
    //ENCADEAMENTO DO Carro Anterior e Proximo Carro 
    novo_carro->carro_ant = NULL;
    novo_carro->prox_carro = NULL; 
    return novo_carro;   
}

void inserir_carro(Sistema * sistema, Carro * carro){
    //VERIFICA SE A LISTA ESTÁ VAZIA OU SE O CÓDIGO DO NOVO CARRO É MENOR DO QUE O PRIMEIRO
    if (!sistema->carro || carro->codigo_carro < sistema->carro->codigo_carro){
        /*REALIZAÇÃO DO ENCADEAMENTO, O NOVO->PROX_CARRO APONTA PARA O PRIMEIRO*/ 
        carro->prox_carro = sistema->carro; 
        if (sistema->carro){
            /*ATUALIZA O ANTERIOR PARA O NOVO CARRO*/
            sistema->carro->carro_ant = carro; 
        }
        /*NOVO CARRO PARA A PRIMEIRA POSIÇÃO*/ 
        sistema->carro = carro;  
        /*O ANTERIOR DO NOVO CARRO É NULL*/
        carro->carro_ant = NULL; 
    } else {
        /*ENCONTRA A POSIÇÃO CORRETA PARA O NOVO CARRO*/ 
        Carro * carro_posicao = sistema->carro; 
        while (carro_posicao && carro_posicao->carro_ant < carro_posicao->prox_carro){
            /*MOVE PARA O PRÓXIMO CARRO*/
            carro_posicao = carro_posicao->prox_carro;
        }
        
        //INSERE O NOVO CARRO NA POSIÇÃO 
        /*O PRÓXICMO DO NOVO CARRO APONTA PARA O PRÓXIMO DO ATUAL*/ 
        carro->prox_carro = carro_posicao->prox_carro; 
        /*O ANTERIOR DO NOVO CARRO APONTA PARA O CARRO ATUAL*/
        carro->carro_ant = carro_posicao; 
        if(carro_posicao->prox_carro){
            /*ATUALIZA O ANTERIOR DO PRÓXIMO CARRO PARA O NOVO CARRO*/
            carro_posicao = carro; 
        }
        /*O PROXIMO DO CARRO ATUAL É O NOVO CARRO*/
        carro_posicao->prox_carro = carro; 
    }
}

void listar_carros(Sistema * sistema){
    Carro * lista_carros = sistema->carro; 
    printf("======= LISTA DE CARROS =======\n");
    while (lista_carros != NULL) {
        printf("CODIGO: %d\nMODELO: %s\nPRECO: %.2f\nDISPONIBILIDADE: %s\n", lista_carros->codigo_carro, lista_carros->modelo, lista_carros->preco_carro ? "DISPONIVEL" : "NÃO DISPONIVEL");
        lista_carros = lista_carros->prox_carro; 
    }  
}

void alugar_carro(Sistema * sistema, const char * documento_cliente, int codigo_carro){
    /*CHAMADA DA FUNÇÃO "buscar_cliente" PARA VERIFICAR SE O CLIENTE JÁ ESTÁ CADASTRADO OU NÃO, PARA PROSSEGUIR NO ALUGUEL*/
    Cliente * cliente = buscar_cliente(sistema, documento_cliente);  
    if(cliente == NULL){
        printf("CLIENTE NÃO CADASTRADO!");
        return;    
    }

    /*INICIALIZAÇÃO DO PONTEIRO COM O PRIMEIRO CARRO DA LISTA*/
    Carro * carro_alugar = sistema->carro; 
    while(carro_alugar != NULL){
        /*VERIFICA SE O CARRO ENCONTRADO POSSUI O MESMO CÓDIGO FORNECIDO*/
        if(carro_alugar->codigo_carro == codigo_carro){
           /*VERIFICA SE O CARRO SOLICITADO ESTÁ DISPONÍVEL*/
           if(carro_alugar->disponibilidade){
            carro_alugar->disponibilidade = 0; 
            printf("CARRO ALUGADO!");
           } else {
            printf("CARRO %d NÃO ESTA DISPONIVEL!"); 
           }
           return; 
        }
        carro_alugar = carro_alugar->prox_carro;
    }
    printf("CARRO %d NÃO ENCONTRADO!"); 
}

void consulta_carros_disponiveis(Sistema * sistema){
    Carro * carro_consulta = sistema->carro; 
    printf("===== CARROS DISPONIVEIS =====");
    while (carro_consulta != NULL){
        if(carro_consulta->disponibilidade){
            printf("CÓDIGO: %d\nMODELO: %s", carro_consulta->codigo_carro, carro_consulta->modelo);
        }
        carro_consulta = carro_consulta->prox_carro; 
    }
    
}

///////////////ERRO
Cliente * cria_cliente(Cliente * cliente, const char * nome, const char * documento, const char * telefone){
    Cliente * novo_cliente = (Cliente*)malloc(sizeof(Cliente));
    if(novo_cliente == NULL){
        printf("NÃO FOI POSSIVEL CRIAR UM CLIENTE!");
        exit(1); 
    }

    strncpy(novo_cliente->nome, nome, sizeof(novo_cliente->nome) - 1);
    novo_cliente->nome[sizeof(novo_cliente->nome) - 1] = '\0'; 
    
    strncpy(novo_cliente->documento_cliente, documento, sizeof(novo_cliente->documento_cliente) - 1);
    novo_cliente->documento_cliente[sizeof(novo_cliente->documento_cliente) - 1] = '\0'; 

    strncpy(novo_cliente->telefone_cliente, telefone, sizeof(novo_cliente->telefone_cliente) - 1); 
    novo_cliente->telefone_cliente[sizeof(novo_cliente->telefone_cliente) - 1] = '\0'; 
    
    Cliente * end = ordena_cliente(cliente, nome);
    if(end == NULL){
        novo_cliente->prox_cliente = cliente; 
        novo_cliente->cliente_ant = end;

        if(cliente != NULL)
           cliente->cliente_ant = novo_cliente; 
           
        return novo_cliente; 
    } else {
        novo_cliente->prox_cliente = end->prox_cliente; 
        novo_cliente->cliente_ant = end; 

        if(end->prox_cliente != NULL)
           end->prox_cliente->cliente_ant = novo_cliente;  

        end->prox_cliente = novo_cliente; 
    }
    return novo_cliente;  
}

int compara_cliente(char * str, char * str_busca){
    //COMPARAÇÃO ENTRE DUAS STRINGS PARA, VERIFICADO QUAL É MAIOR
    return strncmp(str, str_busca, strlen(str_busca));
}

Cliente * ordena_cliente(Cliente * cliente, char * nome){
    /*INDICA O ENDEREÇO DE REFERÊNCIA, INICIALIZADO COM NULL*/
    Cliente * end = NULL; 
    /*PONTEIRO AUXILIAR QUE É INICIALIZADO COM A LISTA "cliente"*/
    Cliente * auxiliar_cliente = cliente; 

    while (auxiliar_cliente != NULL && compara_cliente(auxiliar_cliente->nome, nome) < 0);
    {
        /*end APONTA PARA O VALOR ATUAL DE auxiliar_cliente*/
        end = auxiliar_cliente; 
        /*auxiliar_cliente APONTA PARA O PRÓXIMO VALOR*/
        auxiliar_cliente = auxiliar_cliente->prox_cliente; 
    }
    return end; 
}

Cliente * buscar_cliente(Sistema * sistema, const char * nome){
    Cliente * cliente_desejado = sistema->cliente; 
    while (cliente_desejado){
        if(strcmp(cliente_desejado->nome, nome)){
            return cliente_desejado; 
        }
        cliente_desejado = cliente_desejado->prox_cliente; 
    }
    return NULL; 
}

void editar_cliente(Sistema * sistema, const char *nome){
    Cliente * cliente_editar = buscar_cliente(sistema, nome); 
    if(cliente_editar != NULL){
        printf("==========> EDITANDO CLIENTE: %s\n", cliente_editar->nome); 
        
        printf("- NOVO NOME: ");
        /*LENDO O NOVO NOME A PARTIR DO fgets (QUE LÊ UMA LINHA INTEIRA)*/
        fgets(cliente_editar->nome, MAX_NOME, stdin); 
        /*ENCONTRA O DESLOCAMENTO DA LINHA*/
        cliente_editar->nome[strcspn(cliente_editar->nome, "\n")] = 0;

        printf("- NOVA DATA DE ALUGUEL: "); 
        /*LENDO O A NOVA DATA DO ALUGUEL A PARTIR DO fgets (QUE LÊ UMA LINHA INTEIRA)*/
        fgets(cliente_editar->data_aluguel, 11, stdin); 
        /*ENCONTRA O DESLOCAMENTO DA LINHA*/
        cliente_editar->data_aluguel[strcspn(cliente_editar->data_aluguel, "\n")] = 0; 

        printf("- NOVA DURACAO (DIAS): ");
        scanf(" %d", &cliente_editar->duracao_aluguel);
        getchar();

        printf("- NOVO DOCUMENTO: ");
        /*LENDO O NOVO DOCUMENTO A PARTIR DO fgets (QUE LÊ UMA LINHA INTEIRA)*/
        fgets(cliente_editar->documento_cliente, MAX_DOCUMENTO, stdin);
        /*ENCONTRA O DESLOCAMENTO DA LINHA*/
        cliente_editar->documento_cliente[strcspn(cliente_editar->documento_cliente, "\n")] = 0;
        printf("\nCLIENTE EDITADO COM SUCESSO!");
        printf("================================"); 
    } else {
        printf("ATENCÃO: CLIENTE %s NÃO ENCONTRADO: ", cliente_editar->nome);
    }
}

///////////////ERRO
void excluir_cliente(Sistema * sistema, const char * documento){
    Cliente * cliente_excluir = buscar_cliente(sistema, documento);
    if(cliente_excluir != NULL) {
        if(cliente_excluir->cliente_ant){
        cliente_excluir->cliente_ant->prox_cliente = cliente_excluir->prox_cliente;
    } else {
        sistema->cliente = cliente_excluir->prox_cliente; 
    } 
    if (cliente_excluir->prox_cliente !=NULL) {
        cliente_excluir->prox_cliente->cliente_ant = cliente_excluir->cliente_ant; 
    }
    free(cliente_excluir); 
    printf("CLIENTE %s EXCLUIDO COM SUCESSO!", cliente_excluir->nome);
    } else {
        printf("CLIENTE %s NÃO ENCONTRADO!", cliente_excluir->nome); 
    }
}

int conta_clientes(Sistema * sistema){
    /*CONTARÁ O NÚMERO DE CLIENTES*/
    int conta = 0; 
    /*INICIALIZA O PONTEIRO cliente_conta COM O PRIMEIRO CLIENTE DA LISTA*/
    Cliente * cliente_conta = sistema->cliente; 
    while (cliente_conta != NULL){
        conta++;
        /*ATUALIZA E APONTA PARA O PROXIMO*/
        cliente_conta = cliente_conta->prox_cliente;
    }
    return conta; 
}

///////////////ERRO
void adiciona_cliente(Sistema * sistema, Cliente * cliente){
    /*VERIFICA SE A LISTA ESTÁ VAZIA OU SE O NOVO CLIENTE É O PEIMEIRO*/
    if(!sistema->cliente || strcmp(cliente->nome, sistema->cliente->nome) < 0){
        /*ADICIONA O CLIENTE NO INÍCIO*/
        cliente->prox_cliente = sistema->cliente; 
        /*VERIFICA DE JÁ EXISTE UM CLIENTE NA LISTA*/
        if(sistema->cliente){
            /*CASO EXISTA ATUALIZA O prox_cliente PARA NOVO CLIENTE*/
            sistema->cliente->prox_cliente = cliente; 
        }
        /*INSERE O NOVO CLIENTE NO INÍCIO DA LISTA*/
        sistema->cliente = cliente;
        /*cliente_ant É CONFIGURADO COMO NULL*/
        cliente->cliente_ant = NULL; 
    } 
    /*SE A LISTA NÃO ESTIVER VAZIA OU O NOVO CLIENTE NÃO FOR O PRIMEIRO*/
    else {
        /*INICIALIZA O PONTEIRO cliente_atual COM O PRIMEIRO CLIENTE DA LISTA*/
        Cliente * cliente_atual = sistema->cliente;
        /*ENQUANTO A LISTA TIVER CLIENTE E O NOME DO NOVO CLIENTE ESTIVER EM ORDEM, EM RELAÇAO AO PRÓXIMO CLIENTE*/
        while (cliente_atual->prox_cliente && strcmp(cliente->nome, cliente_atual->prox_cliente) > 0);{
            /*INSERINDO O CLIENTE NA POSIÇÃO ENCONTRADA*/
            cliente_atual = cliente_atual->prox_cliente; 
        }
        cliente->prox_cliente = cliente_atual->prox_cliente; 
        cliente->cliente_ant = cliente_atual;
        if(cliente_atual->prox_cliente){
            cliente_atual->prox_cliente->cliente_ant = cliente; 
        } 
        cliente_atual->prox_cliente = cliente; 
    }
}

void salva_dados(Sistema * sistema){
    /*ABRE/CRIA O ARQUIVO "clientes.txt"*/
    FILE* arquivo = fopen("clientes.txt", "w"); 
    if(arquivo == NULL){
        printf("ERRO AO ABRIR O ARQUIVO!");
        exit(1); 
    }

    /*INICIA salva_cliente COM O PRIMEIRO CLIENTE DA LISTA DE CLIENTES*/
    Cliente * salva_cliente = sistema->cliente; 
    while (salva_cliente != NULL){
        fprintf(arquivo, "%s;%s;%s;%d;", salva_cliente->nome, salva_cliente->documento_cliente, salva_cliente->data_aluguel, salva_cliente->duracao_aluguel);
    }
    fclose(arquivo); 
}

void carrega_dados(Sistema * sistema){
    /*ABRE O ARQUIVO*/
    FILE * arquivo = fopen("clientes.txt", "r"); 
    if(arquivo == NULL){
        printf("ERRO AO ABRIR O ARQUIVO!");
        return; 
    }    

    char linha[200]; /*ARMAZENARÁ CADA LINHA DO ARQUIVO*/
    while (fgets(linha, sizeof(linha), arquivo)){
        char nome_cliente[MAX_NOME]; 
        char data_aluguel[11]; 
        char documento_cliente[MAX_DOCUMENTO]; 
        int duracao_aluguel; 
        sscanf(linha,"NOME: %s - DOCUMENTO: %s - DATA DO ALUGUEL: %s - DURACAO: %d (DIA/DIAS);", nome_cliente, documento_cliente, data_aluguel, duracao_aluguel);
        Cliente * cliente = cria_cliente(nome_cliente, documento_cliente, data_aluguel, duracao_aluguel);
        adiciona_cliente(sistema, cliente);
    }
    fclose(arquivo); 
}

void libera_memoria(Sistema * sistema){
    /*INICIALIZA O PONTEIRO PARA O PRIMEIRO CLIENTE NA LISTA DE CLIENTES*/
    Cliente * cliente_atual = sistema->cliente; 
    /*ENQUANRO NÃO PERCORRER TODA A LISTA*/
    while (cliente_atual != NULL){
        /*PONTEIRO AUZILIAR QUR ARMAZENARÁ O CLIENTE ATUAL*/
        Cliente * auxiliar_cliente = cliente_atual;
        /*AVANÇA cliente_atual PARA O PRÓXIMO NÓ DA FILA*/
        cliente_atual = cliente_atual->prox_cliente;
        /*LIBERA MEMÓRIA*/
        free(auxiliar_cliente);  
    }
    Carro * carro_atual = sistema->carro; 
    while (carro_atual != NULL)
    {
        /*PONTEIRO AUXILIAR QUE ARMAZENARÁ O CARRO ATUAL*/
        Carro * auxiliar_carro = carro_atual;
        /*AVANÇA carro_atual PARA O PRÓXIMO NÓ DA FILA*/
        carro_atual = auxiliar_carro->prox_carro; 
        /*LIBERA MEMÓRIA*/
        free(alugar_carro);  
    }
}